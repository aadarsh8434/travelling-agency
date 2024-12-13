#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to store destination details
struct Destination {
    string name;
    double price;
};

// Structure to store customer details
struct Customer {
    string name;
    int age;
    string destination;
    double price;
};

// Function to display available destinations
void displayDestinations(const vector<Destination>& destinations) {
    cout << "\nAvailable Destinations:" << endl;
    cout << left << setw(20) << "Destination" << "Price (USD)" << endl;
    cout << "-----------------------------------" << endl;
    for (size_t i = 0; i < destinations.size(); ++i) {
        cout << left << setw(20) << destinations[i].name << destinations[i].price << endl;
    }
}

// Function to book a trip
void bookTrip(const vector<Destination>& destinations, vector<Customer>& customers) {
    string customerName;
    int customerAge;
    int choice;

    cout << "\nEnter customer name: ";
    cin.ignore();
    getline(cin, customerName);

    cout << "Enter customer age: ";
    cin >> customerAge;

    displayDestinations(destinations);

    cout << "\nEnter the number of the destination you want to book (1 to " << destinations.size() << "): ";
    cin >> choice;

    if (choice < 1 || choice > destinations.size()) {
        cout << "Invalid choice!" << endl;
        return;
    }

    Customer customer;
    customer.name = customerName;
    customer.age = customerAge;
    customer.destination = destinations[choice - 1].name;
    customer.price = destinations[choice - 1].price;

    customers.push_back(customer);

    cout << "\nTrip booked successfully for " << customer.name << " to " << customer.destination << ".\n";
}

// Function to display all bookings
void displayBookings(const vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "\nNo bookings available." << endl;
        return;
    }

    cout << "\nAll Bookings:" << endl;
    cout << left << setw(20) << "Name" << setw(10) << "Age" << setw(20) << "Destination" << "Price (USD)" << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (const auto& customer : customers) {
        cout << left << setw(20) << customer.name << setw(10) << customer.age << setw(20) << customer.destination << customer.price << endl;
    }
}

int main() {
    vector<Destination> destinations = {
        {"Paris", 1200.50},
        {"New York", 950.75},
        {"Tokyo", 1300.00},
        {"Dubai", 800.30},
        {"Sydney", 1500.00}
    };

    vector<Customer> customers;

    int choice;

    do {
        cout << "\n--- Traveling Agency System ---" << endl;
        cout << "1. View Destinations" << endl;
        cout << "2. Book a Trip" << endl;
        cout << "3. View All Bookings" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayDestinations(destinations);
                break;
            case 2:
                bookTrip(destinations, customers);
                break;
            case 3:
                displayBookings(customers);
                break;
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
