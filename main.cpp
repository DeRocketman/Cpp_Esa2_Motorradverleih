#include <iostream>
#include <fstream>
#include <list>

using namespace std;

class Address {
private:
    string street;
    string number;
    string zip;
    string city;
public:
    friend istream& operator>>(istream& is, Address& address);
    friend ostream& operator<<(ostream& os, const Address& address);
};

istream &operator>>(istream& is, Address &address) {
    if (&is == &cin) {
        cout << "Adressdaten eingeben: " << endl;
        cout << "Straße: ";
        do {
            getline(is, address.street);
        } while (address.street.empty());
        cout << "Hausnummer: ";
        do {
            getline(is, address.number);
        } while (address.number.empty());
        cout << "Postleitzahl: ";
        do {
            getline(is, address.zip);
        } while (address.zip.empty());
        cout << "Stadt: ";
        do {
            getline(is, address.city);
        } while (address.city.empty());
    } else {
        getline(is, address.street);
        getline(is, address.number);
        getline(is, address.zip);
        getline(is, address.city);
    }
    return is;
}

ostream& operator<<(ostream& os, const Address& address) {
    if (&os == &cout) {
        os << address.street << " " << address.number << " " << address.zip << " " << address.city << " ";
    } else {
        os << address.street << endl << address.number << endl << address.zip << endl << address.city << endl;
    }

    return os;
}

class Customer {
private:
    string name;
    string firstName;
    Address address;
    int yearBirth;
    string phone;
    bool hasLicence;
    bool hasReserved;
public:
    friend istream& operator>>(istream& is, Customer& customer);
    friend ostream& operator<<(ostream& os, const Customer& customer);

    string getFirstName() const {
        return firstName;
    }

    string getName() const {
        return name;
    }

    bool getHasLicence() const {
        return hasLicence;
    };
};

istream &operator>>(istream& is, Customer &customer) {
    if (&is == &cin) {
        cout << "Kundendaten eingeben: " << endl;
        cout << "Vorname: ";
        do {
            getline(is, customer.firstName);
        } while (customer.firstName.empty());

        cout << "Name: ";
        do {
            getline(is, customer.name);
        } while (customer.name.empty());
        is >> customer.address;
        cout << "Geburtsjahr: ";
        do {
            try {
                is >> customer.yearBirth;
                if (customer.yearBirth > 2004) {
                    throw 1;
                }
            } catch (int err) {
                if (err==1) {
                    cout << "Leider ist der Kunde noch zu jung! Vorgang wird abgebrochen!" << endl ;
                    customer.hasLicence = false;
                    return  is;
                }
            }
        } while (customer.yearBirth == 0);
        cout << "Telefonnummer: ";
        do {
            getline(is, customer.phone);
        } while (customer.phone.empty());
        cout << "Besitzt Fahrerlaubnis Kl. A? [1]ja / [0]nein:" << endl;
        is >> customer.hasLicence;
        if (customer.hasLicence) {
            cout << "Hat bereits ein Motorrad reserviert? [1]ja / [0]nein:" << endl;
            is >> customer.hasReserved;
        } else {
            cout << "Kunden müssen eine Fahrerlaubnis der Klasse A haben! Vorgang wird abgebrochen!" << endl;
        }
    } else {
        getline(is, customer.firstName);
        getline(is, customer.name);
        is >> customer.address;
        is >>customer.yearBirth;
        getline(is, customer.phone);
        is >> customer.hasLicence;
        is >> customer.hasReserved;
    }
    return is;
}

ostream& operator<<(ostream& os, const Customer& customer) {
    if (&os == &cout) {
        os << customer.name << " " << customer.firstName << " " << customer.address << customer.yearBirth << " "
           << customer.phone << " " << customer.hasLicence << " " << customer.hasReserved << endl;
    }
    return os;
}

class Bike {
private:
    string registrationNumber;
    string type;
    bool isReserved;
public:
    Bike() {};
    Bike(string reg, string type) : registrationNumber(reg), type(type) {};
    friend istream& operator>>(istream& is, Bike& bike);
    friend ostream& operator<<(ostream& os, const Bike& bike);

    string getType() const {
        return type;
    }

    bool getIsReserved() const {
        return isReserved;
    }
};

istream &operator>>(istream& is, Bike &bike) {
    if (&is == &cin) {
        cout << "Bitte geben Sie die Daten für das Motorrad ein: " << endl;
        cout << endl << "Kennzeichen: ";
        is >> bike.registrationNumber;
        cout << "Type: ";
        is >> bike.type;
        cout << "Ist Motorrad schon verliehen oder reserviert? [1]ja / [0]nein";
        is >> bike.isReserved;
    } else {
        is >> bike.registrationNumber;
        is >> bike.isReserved;
    }
    return is;
}

ostream& operator<<(ostream& os, const Bike& bike) {
    os << bike.registrationNumber << " " << bike.type << " " << bike.isReserved << endl;
    return os;
}

class Reservation {
private:
    int id;
    string customerFirstName;
    string customerName;
    string bikeType;
public:
    friend istream& operator>>(istream& is, Reservation& reservation);
    friend ostream& operator<<(ostream& os, const Reservation& reservation);
};

istream &operator>>(istream& is, Reservation &reservation) {
    if (&is == &cin) {
        cout << "Bitte ID eingeben";
        is >> reservation.id;
    } else {
        is >> reservation.id;
        getline(is, reservation.customerFirstName);
        getline(is, reservation.customerName);
        getline(is, reservation.bikeType);
    }
    return is;
}

ostream& operator<<(ostream& os, const Reservation& reservation) {
    if (&os == &cout) {
        os << reservation.id << " " << reservation.customerFirstName << " " << reservation.customerName << " " << reservation.bikeType << endl;
    } else {
        os << reservation.id << endl << reservation.customerFirstName << endl << reservation.customerName << endl << reservation.bikeType << endl;
    }
    return os;
}
class BikeRental {
private:
    list<Customer> customers;
    list<Reservation> reservations;
    list<Bike> bikes;
public:
    void showMainMenu();
    void readDataFromFile(int fileId);
    void writeDataToFile(int fileId);
    void showCustomerManagement();
    void showReservationManagement();
    void showBikeManagement();
    void createNewCustomer();
    void editCustomerData();
    void deleteCustomerData();
    void showAllCustomersData();
    Customer searchCustumer(const string& customerFirstName, const string& customerName);
    void createNewReservation();
    void editReservation();
    void showAllReservations();
};

void BikeRental::showMainMenu() {
    int choice=5;

    //readDataFromFile(2);
    readDataFromFile(3);

    while (choice!=0) {
        cout << "----------MEN\x9A \b-----------" << endl;
        cout << "[1] Kundinnenverwaltung" << endl;
        cout << "[2] Reservierungen" << endl;
        cout << "[3] Motorradverwaltung" << endl;
        cout << "[0] Beenden" << endl;
        cout << "--------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice==1) {
            showCustomerManagement();
        } else if (choice==2) {
            showReservationManagement();
        } else if (choice==3) {
            showBikeManagement();
        } else if (choice==0) {
            writeDataToFile(1);
            writeDataToFile(2);
            writeDataToFile(3);
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
            Reservation tempReservation;
            while(!readBikeFile.eof()) {
                readReservationFile >> tempReservation;
                reservations.push_back(tempReservation);
            }
        }
    } else if (fileId == 2) {
        if (readBikeFile.fail()) {
            int defaultBikes = 1;
            cout << "Keine Bikes vorhanden" << endl;
            cout << "Soll Grundstock geschrieben/geladen werden? (Demo-Modus)" << endl;
            cout << "[1]ja / [0]nein" << endl;
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
        } else {
            Bike tempBike;
            while(!readBikeFile.eof()) {
                readBikeFile >> tempBike;
                bikes.push_back(tempBike);
            }
        }
    } else {
        if (readCustomerFile.fail()) {
            cout << "Keine Kundendaten vorhanden!" << endl;
        } else {
            Customer tempCustomer;
            while(readCustomerFile >> tempCustomer) {
                customers.push_back(tempCustomer);
            }
        }
    }
}

void BikeRental::writeDataToFile(int fileId) {
    ofstream writeReservationFile("reservierungen.txt", ios::app);
    ofstream writeBikeFile("bikes.txt",ios::app);
    ofstream writeCustomerFile("kunden.txt", ios::app);

    if (fileId==1) {
        for (const auto& reservation: reservations) {
            writeReservationFile << reservation;
        }
    } else if (fileId==2) {
        for (const auto& bike: bikes) {
            writeBikeFile << bike;
        }
    } else {
        for (const auto& customer: customers) {
            writeCustomerFile << customer;
        }
    }
}

void BikeRental::showCustomerManagement() {
    int choice=5;
    while(choice!=0) {
        cout << "----------Kundenverwaltung-----------" << endl;
        cout << "[1] Neue Kundin anlegen" << endl;
        cout << "[2] Kundin bearbeiten" << endl;
        cout << "[3] Kundin löschen" << endl;
        cout << "[4] Alle Datensätze anzeigen" << endl;
        cout << "[0] Beenden und zur\x9A \bck gehen" << endl;
        cout << "-------------------------------------" << endl;
        cout << endl << "Ihre Auswahl: ";
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

void BikeRental::createNewCustomer() {
    bool isCustomerKnown = false;
    int choice = 1;
    Customer tempCustomer;
    cin >> tempCustomer;

    for (const auto& customer: customers) {
        if (customer.getName() == tempCustomer.getName() && customer.getFirstName() == tempCustomer.getFirstName()) {
            isCustomerKnown = true;
        }
    }

    if (isCustomerKnown) {
        cout << "Kunde ist bereits angelegt!" << endl;
        cout << "Sollen die Kundendetails angezeigt werden? [1]ja / [0]nein" << endl;
        cout << endl << "Ihre Auswahl: ";
        cin >> choice;
    } else {
        if (tempCustomer.getHasLicence()) {
            cout << "Sollen die erfassten Kundendaten gespeichert werden? [1]ja / [0]nein" << endl;
            cout << endl << "Ihre Auswahl: ";
            cin >> choice;
            if (choice == 1) {
                customers.push_back(tempCustomer);
                writeDataToFile(3);
            }
        }
    }
}

void BikeRental::editCustomerData() {

}

void BikeRental::deleteCustomerData() {}

void BikeRental::showAllCustomersData() {}

Customer BikeRental::searchCustumer(const string& customerFirstName, const string& customerName) {
    for (const auto& customer: customers) {
        if (customerName == customer.getName() && customerFirstName == customer.getFirstName()) {
            return customer;
        }
    }
    Customer fail;
    return fail;
}

void BikeRental::showReservationManagement() {
    int choice=6;

    while(choice!=0) {
        cout << "----------Reservierungen-----------" << endl;
        cout << "[1] Neue Reservierung " << endl;
        cout << "[2] Reservierung bearbeiten" << endl;
        cout << "[3] Alle Reservierungen anzeigen" << endl;
        cout << "[0] Beenden und zur\x9A \bck gehen" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl << "Ihre Auswahl:";
        cin >> choice;

        if (choice==0) {
            cout << "Reservierungsverwaltung wird geschlossen";
        } else if (choice==1) {
            createNewReservation();
        }
    }
}

void BikeRental::createNewReservation() {
    int i = 0;
    int choice = -1;
    Bike tempBike;
    cout << "-------Neue Reservierung-------" << endl;
    cout << "I. Bike auswählen" << endl;
    for (const auto& bike : bikes) {
        cout << i << ") " << bike << endl;
        i++;
    }
    cout << endl << "Ihre Auswahl:";
    cin >> choice;

    for (const auto& bike : bikes) {
        if (choice == i) {
            if (!bike.getIsReserved()) {
                tempBike = bike;
                break;
            } else {
                cout << "Motorrad ist schon reserviert";
                choice = -1;
            }
        } else {
            i--;
        }
    }

}
void BikeRental::showBikeManagement() {}

int main() {
    BikeRental bikeRental;
    bikeRental.showMainMenu();
    return 0;
}
