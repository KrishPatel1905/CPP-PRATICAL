#include <iostream>
#include <string>
using namespace std;

int main() {
    double loanAmount, annualIncome, ratio;

    cout << "Welcome to the Loan-to-Income Ratio Calculator!\n";

    try {
        cout << "Enter the total loan amount: ";
        cin >> loanAmount;

        if (loanAmount <= 0) {
            throw string("Loan amount must be a positive number.");
        }

        cout << "Enter your annual income: ";
        cin >> annualIncome;

        if (annualIncome <= 0) {
            throw string("Annual income must be a positive number.");
        }

        ratio = loanAmount / annualIncome;
        cout << "The loan-to-income ratio is: " << ratio << endl;
    }
    catch (string error) {
        cout << "Error: " << error << endl;
    }

    return 0;
}
