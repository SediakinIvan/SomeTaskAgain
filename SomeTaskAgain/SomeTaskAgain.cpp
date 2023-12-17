
#include <iostream>
#include <string>
using namespace std;

class Company {
public:
    string companyName;
    int companyEmployeeCount;
    float annualIncome;
    float annualTurnover;

    Company() : companyName("Default_comp"), companyEmployeeCount(1), annualIncome(0.0), annualTurnover(0.0) {}

    Company(string name, int number, float income, float turnover) : companyName(name), companyEmployeeCount(number), annualIncome(income), annualTurnover(turnover) {}

    void printCompanyInfo() {
        cout << "Company: " << companyName << ", People: " << companyEmployeeCount << "Annual Income: " << annualIncome << "millions, Annual Turnover: " << annualTurnover << "millions" << endl;
    }
};

class Employee {
public:
    string emp_Name;
    int emp_Age;
    bool truckLicense;
    int drivingExperience;

    Employee() : emp_Name("Default Name"), emp_Age(0), truckLicense(false), drivingExperience(0) {}

    Employee(string name, int age, bool have, int years) : emp_Name(name), emp_Age(age), truckLicense(have), drivingExperience(years) {}

    void printEmployeeInfo() {
        cout << "Employee: " << emp_Name << ", Age: " << emp_Age << ", Drives trucks: " << (truckLicense ? "Yes" : "No") << ", Years of driving: " << drivingExperience << endl;
    }
};

class Vehicle {
public:
    string vehicleType;
    string plates;
    int creationYear;
    int accidentsCount;

    Vehicle() : vehicleType("Default Vehicle"), plates("AA000A174"), creationYear(0), accidentsCount(0) {}

    Vehicle(string type, string plate, int year, int accident) : vehicleType(type), plates(plate), creationYear(year), accidentsCount(accident) {}

    void printVehicleInfo() {
        cout << "Vehicle Type: " << vehicleType << ", Plates:" << plates <<", Year: " << creationYear << ", Had" << accidentsCount << "accidents" << endl;
    }
};

class Truck : public Vehicle {
public:
    int maximumLoad;
    int axlesNumber;

    Truck() : maximumLoad(0), axlesNumber(2) {}

    Truck(int load, int axles, string type, string plates, int year, int accident) : maximumLoad(load), axlesNumber(axles), Vehicle(type, plates, year, accident) {}

    Truck(int load, int axles, Vehicle& vehicle) : maximumLoad(load), axlesNumber(axles), Vehicle(vehicle) {}

    void printTruckInfo() {
        cout << "Capacity: " << maximumLoad << " tons, Axles: " << axlesNumber << endl;
    }
};

class Car : public Vehicle {
public:
    int numberOfSeats;
    string fuelType;

    Car() : numberOfSeats(5), fuelType("Petrol") {}

    Car(int seats, string fuel, string type, string plates, int year, int accident) : numberOfSeats(seats), fuelType(fuel), Vehicle(type, plates, year, accident) {}


    Car(int seats, string fuel, Vehicle& vehicle) : numberOfSeats(seats), fuelType(fuel), Vehicle(vehicle) {}

    void printCarInfo() {
        cout << "Seats: " << numberOfSeats << ", Fuel: " << fuelType << endl;
    }
};

int main() {
    Company c1("RUDN", 1000, 10, 100);
    c1.printCompanyInfo();

    Employee e1("Roman", 22, false, 2);
    e1.printEmployeeInfo();

    Truck t1(5, 3, "Truck", "A123AP169", 2007, 0);
    Car car1(7, "Petrol", "Sedan", "X218HX174", 2021, 2);


    t1.printVehicleInfo();
    t1.printTruckInfo();
    car1.printVehicleInfo();
    car1.printCarInfo();



    return 0;
}