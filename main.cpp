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
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
