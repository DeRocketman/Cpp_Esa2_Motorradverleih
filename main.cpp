#include <iostream>

using namespace std;

class Address {
    string street;
    string number;
    string zip;
    string city;
    string country;

};

class Customer {
private:
    string name;
    string firstName;
    Address address;
    int yearBirth;
    string phone;
    bool hasLicence;
public:

    friend istream& operator>>(istream& is, Customer& customer);
    friend ostream& operator<<(ostream& os, const Customer& customer);
};

istream &operator>>(istream& is, Customer &customer) {
    return is;
}

ostream& operator<<(ostream& os, const Customer& customer) {
    return os;
}

class Date {
private:
    int year;
    int month;
    int day;
public:
    Date(int y, int m, int d): year(y), month(m), day(d) {};
};

class Bike {
private:
    string registrationNumber;
    string type;
public:

};
class Reservation {
private:
    int id;
    Date rentalStart;
    Date rentalEnd;
    Customer customer;
    Bike bike;
public:
};

class BikeRental {
private:
public:
    void showMainMenu();

};

void BikeRental::showMainMenu() {
    int choice=5;
    while (choice!=0) {
        cout << "----------MENÜ-----------" << endl;
        cout << "[1] Kundenverwaltung" << endl;
        cout << "[2] Reservierungen" << endl;
        cout << "[0] Beenden" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice==1) {

        } else if (choice==2) {

        }
    }
}
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
