#include <iostream>
#include <stdexcept>

using namespace std;

int calculateRatio(int loan, int income) {
    if (income == 0) {
        throw runtime_error    ("Income cannot be zero.");
    }

    return (loan * 100) / income;
}

int main() {
    int loan, income;

    try {
        cout << "Enter loan amount: ";
        cin >> loan;

        cout << "Enter annual income: ";
        cin >> income;

        int ratio = calculateRatio(loan, income);
        cout << "\nLoan-to-Income Ratio: " << ratio << "%\n";
    } 
    catch (exception& e) {
        cout << "\nError: " << e.what() << endl;
    }

    return 0;
}
