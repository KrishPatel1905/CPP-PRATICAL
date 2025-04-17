#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
  
  Employee(string empName, double empSalary, double empBonus = 5000.0) {
    name = empName;
    basicSalary = empSalary;
    bonus = empBonus;
}

    inline double totalSalary() {
        return basicSalary + bonus;
    }

   
    void displayDetails() {
        cout << "Name: " << name << " | Basic Salary: " << basicSalary
             << " | Bonus: " << bonus << " | Total Salary: " << totalSalary() << endl;
    }
};

int main() {
    int numEmployees;
    cout << "Enter number of employees: ";
    cin >> numEmployees;

    Employee* employees[10]; 

    for (int i = 0; i < numEmployees; i++) {
        string name;
        double salary, bonus;
        cout << "Enter name, basic salary, and bonus for employee " << i + 1 << ": ";
        cin >> name >> salary >> bonus;
        employees[i] = new Employee(name, salary, bonus);
    }

    cout << "\nEmployee Salary Details:\n";
    for (int i = 0; i < numEmployees; i++) {
        employees[i]->displayDetails();
    }

    return 0;
}
