#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }

    void displayPerson() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(string n, int a, int id) : Person(n, a) {
        employeeID = id;
    }

    void displayEmployee() {
        displayPerson();
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Manager : public Employee {
private:
    string department;
public:
    Manager(string n, int a, int id, string dept) : Employee(n, a, id) {
        department = dept;
    }

    void displayManager() {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

int main() {
    Manager m1("KRISH", 35, 101, "Sales");
    Manager m2("HEET", 40, 102, "Marketing");
    Manager m3("URVAL", 38, 103, "Finance");

    cout << "Manager 1 Details:\n";
    m1.displayManager();
    cout << "\n";

    cout << "Manager 2 Details:\n";
    m2.displayManager();
    cout << "\n";

    cout << "Manager 3 Details:\n";
    m3.displayManager();
    cout << "\n";

    return 0;
}
