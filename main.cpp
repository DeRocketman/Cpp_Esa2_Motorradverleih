#include <iostream>
#include <fstream>
#include <list>

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
    Bike(string reg, string type) : registrationNumber(reg), type(type) {};
    friend istream& operator>>(istream& is, Bike& bike);
    friend ostream& operator<<(ostream& os, const Bike& bike);
};

istream &operator>>(istream& is, Bike &bike) {
    return is;
}

ostream& operator<<(ostream& os, const Bike& bike) {
    os << bike.registrationNumber << " "<< bike.type << endl;
    return os;
}

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
    list<Customer> customers;
    list<Reservation> reservations;
    list<Bike> bikes;
public:
    void showMainMenu();
    void readDataFromFile(int fileId);
    void writeDataToFile();
    void showCustomerManagement();
    void showReservationManagement();
    void createNewCustomer();
    void editCustomerData();
    void deleteCustomerData();
    void showAllCustomersData();
};

void BikeRental::showMainMenu() {
    int choice=5;
    while (choice!=0) {
        cout << "----------MEN\x9A \b-----------" << endl;
        cout << "[1] Kundinnenverwaltung" << endl;
        cout << "[2] Reservierungen" << endl;
        cout << "[0] Beenden" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice==1) {
            showCustomerManagement();
        } else if (choice==2) {
            showReservationManagement();
        } else if (choice==0) {
            cout << "Programm wird beendet" << endl;
        }
    }
}

void BikeRental::readDataFromFile(int fileId) {
    ifstream readReservationFile("reservierungen.txt");
    ifstream readBikeFile("motorraeder.txt");
    ifstream readCustomerFile("kunden.txt");
    if (fileId == 1) {
        if (readReservationFile.fail()) {
            cout << "Keine Reservierungen vorhanden" << endl;
        } else {

        }
    } else if (fileId == 2) {
        if (readBikeFile.fail()) {
            int defaultBikes = 1;
            cout << "Keine Bikes vorhanden" << endl;
            cout << "Soll Grundstock geschrieben/geladen werden? (Demo-Modus)" << endl;
            cout << "[0] nein / [1] ja " << endl;
            cout << endl << "Ihre Auswahl:";
            cin >> defaultBikes;

            if(defaultBikes == 1) {
                ofstream writeDemoBike("motorraeder.txt");
                Bike b[4] = {{"HH-CPP2022","Suzuki Bandit"},{"HH-CPP22","Honda TransAlp"}, {"HH-CPP022","BMW F 650 GS"}, {"HH-CPP1","Kawasaki ZZR1400"}};
                for (const auto & i : b) {
                    bikes.push_back(i);
                    writeDemoBike << i;
                }
            }
        }
    } else {

    }
}

void BikeRental::writeDataToFile() {}

void BikeRental::showCustomerManagement() {
    int choice=5;
    readDataFromFile(2);
    while(choice!=0) {
        cout << "----------Kundenverwaltung-----------" << endl;
        cout << "[1] Neue Kundin anlegen" << endl;
        cout << "[2] Kundin bearbeiten" << endl;
        cout << "[3] Kundin löschen" << endl;
        cout << "[4] Alle Datensätze anzeigen" << endl;
        cout << "[0] Beenden und zur\x9A \bck gehen" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice==1) {
            createNewCustomer();
        } else if(choice==2) {
            editCustomerData();
        } else if(choice==3) {
            deleteCustomerData();
        }else if (choice==4) {
            showAllCustomersData();
        } else if(choice==0) {
            cout << "Kundenverwaltung geschlossen" << endl;
        }
    }
}

void BikeRental::createNewCustomer() {}

void BikeRental::editCustomerData() {}

void BikeRental::deleteCustomerData() {}

void BikeRental::showAllCustomersData() {}

void BikeRental::showReservationManagement() {}

int main() {
    BikeRental bikeRental;
    bikeRental.showMainMenu();
    return 0;
}
