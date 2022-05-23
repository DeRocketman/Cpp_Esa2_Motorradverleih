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
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
