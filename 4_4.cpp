#include <iostream>
using namespace std;

class BankAccount {
protected:
    int accNumber;
    double accBalance;
    double prevTransaction;

public:
    BankAccount(int accNo, double initialBal) {
        accNumber = accNo;
        accBalance = initialBal;
        prevTransaction = 0.0;
    }

    virtual ~BankAccount() {
        cout << "BankAccount " << accNumber << "] is  closed.\n";
    }

    virtual void AddFunds(double amount) {
        accBalance += amount;
        prevTransaction = amount;
        cout << "Deposited: " << amount << "  New Balance: " << accBalance << endl;
    }

    virtual void RemoveFunds(double amount) {
        if (amount <= accBalance) {
            accBalance -= amount;
            prevTransaction = -amount;
            cout << "Withdrawn: " << amount << "  New Balance: " << accBalance << endl;
        } else {
            cout << "Insufficient balance for withdrawal.\n";
        }
    }

    void RevertTransaction() {
        accBalance -= prevTransaction;
        cout << "Reverted Last Transaction: " << prevTransaction
             << "  New Balance: " << accBalance << endl;
        prevTransaction = 0;
    }

    virtual void ShowAccountInfo() {
        cout << "Account Number: " << accNumber
             << "  Balance: " << accBalance << endl;
    }
};

class SavingsAccount : public BankAccount {
private:
    double rateOfInterest;

public:
    SavingsAccount(int accNo, double initialBal, double rate)
        : BankAccount(0, 0)
    {
        accNumber = accNo;
        accBalance = initialBal;
        prevTransaction = 0.0;
        rateOfInterest = rate;
    }

    void AddInterest() {
        double interest = accBalance * rateOfInterest / 100;
        AddFunds(interest);
        cout << "Applied Interest: " << interest
             << "  New Balance: " << accBalance << endl;
    }

    void ShowAccountInfo() {
        BankAccount::ShowAccountInfo();
        cout << "Interest Rate: " << rateOfInterest << "%" << endl;
    }
};

class CurrentAccount : public BankAccount {
private:
    double limitOverdraft;

public:
    CurrentAccount(int accNo, double initialBal, double limit)
        : BankAccount(0, 0)
    {
        accNumber = accNo;
        accBalance = initialBal;
        prevTransaction = 0.0;
        limitOverdraft = limit;
    }

    void RemoveFunds(double amount) {
        if (amount <= accBalance + limitOverdraft) {
            accBalance -= amount;
            prevTransaction = -amount;
            cout << "Withdrawn: " << amount
                 << "  New Balance: " << accBalance << endl;
        } else {
            cout << "Overdraft limit exceeded.\n";
        }
    }

    void ShowAccountInfo() {
        BankAccount::ShowAccountInfo();
        cout << "Overdraft Limit: " << limitOverdraft << endl;
    }
};

int main() {
    SavingsAccount savings(1001, 5000, 3.5);
    CurrentAccount current(2001, 3000, 1000);

    cout << "=== Savings Account ===" << endl;
    savings.ShowAccountInfo();
    savings.AddFunds(1000);
    savings.RemoveFunds(1500);
    savings.AddInterest();
    savings.RevertTransaction();

    cout << endl;

    cout << "=== Current Account ===" << endl;
    current.ShowAccountInfo();
    current.AddFunds(2000);
    current.RemoveFunds(4500);
    current.RemoveFunds(6000);
    current.RevertTransaction();

    return 0;
}
