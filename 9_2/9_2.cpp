#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

class BankAccount {
public:
    string name;
    float balance;
    string transactionType[MAX];
    float transactionAmount[MAX];
    int txnCount;

    
    BankAccount() {
        name = "";
        balance = 0;
        txnCount = 0;
    }

    void createAccount(string userName, float initialAmount) {
        name = userName;
        balance = initialAmount;
        cout << "Account created for " << name << " with $" << balance << " balance.\n";
    }

    void deposit(float amount) {
        if (amount <= 0) {
            throw string("Deposit must be positive!");  
        }
        balance += amount;
        transactionType[txnCount] = "Deposit";
        transactionAmount[txnCount] = amount;
        txnCount++;
        cout << "Deposited $" << amount << ". New balance: $" << balance << "\n";
    }

    void withdraw(float amount) {
        if (amount <= 0) {
            throw string("Withdrawal must be positive!");
        }
        if (amount > balance) {
            throw string("Insufficient funds!");
        }
        balance -= amount;
        transactionType[txnCount] = "Withdraw";
        transactionAmount[txnCount] = amount;
        txnCount++;
        cout << "Withdrew $" << amount << ". Remaining balance: $" << balance << "\n";
    }

    void checkBalance() {
        cout << "Current Balance: $" << balance << "\n";
    }

    void showHistory() {
        if (txnCount == 0) {
            cout << "No transactions made.\n";
            return;
        }
        cout << "\nTransaction History:\n";
        for (int i = 0; i < txnCount; i++) {
            cout << i + 1 << ". " << transactionType[i] << ": $" << transactionAmount[i] << "\n";
        }
    }
};



void showError(string function, string error) {
    cout << "[ERROR] in " << function << ": " << error << "\n";
}

int main() {
    BankAccount acc;
    string userName;
    float initialAmount;
    int choice;
    float amount;

    cout << "Enter your name: ";
    cin >> userName;
    cout << "Enter initial deposit: ";
    cin >> initialAmount;
    acc.createAccount(userName, initialAmount);

menu:
    cout << "\n--- Bank Menu ---\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Check Balance\n";
    cout << "4. Show Transaction History\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            try {
                acc.deposit(amount);
            } catch (string msg) {
                showError("deposit", msg);
            }
            goto menu;

        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            try {
                acc.withdraw(amount);
            } catch (string msg) {
                showError("withdraw", msg);
            }
            goto menu;

        case 3:
            acc.checkBalance();
            goto menu;

        case 4:
            acc.showHistory();
            goto menu;

        case 5:
            cout << "Thank you for using our banking system!\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
            goto menu;
    }

    return 0;
}
