#include <iostream>
#include <cstring>

using namespace std;

class AccountDetails {
    char name[25];
    long int AccNumber=0;
    long int Balance = 0;

public:
    void AddDetail();
    void DepositAmount(long int);
    void WithdrawAmount(long int);
    void ViewDetail(long int);
};

void AccountDetails::AddDetail() {
    AccNumber=AccNumber+1;
    cout << "Enter the Holder name: ";
    cin >> name;
    cout << "Enter the deposite amount: ";
    cin >> Balance;
    cout<<"Your bank account number :"<<AccNumber<<endl;
    cout << "Account created successfully!\n";
}

void AccountDetails::DepositAmount(long int x) {
    if (x == AccNumber) {
        long int amount;
        cout << "Enter the deposit amount: ";
        cin >> amount;
        Balance += amount;
        cout << "Now your current balance is: " << Balance << endl;
    } else {
        cout << "Account number not found.\n";
    }
}

void AccountDetails::WithdrawAmount(long int x) {
    if (x == AccNumber) {
        long int amount;
        cout << "Enter the withdraw amount: ";
        cin >> amount;
        if (amount > Balance) {
            cout << "Insufficient balance!\n";
        } else {
            Balance -= amount;
            cout << "Now your current balance is: " << Balance << endl;
        }
    } else {
        cout << "Account number not found.\n";
    }
}

void AccountDetails::ViewDetail(long int x) {
    if (x == AccNumber) {
        cout << "The Account Number is: " << AccNumber << endl;
        cout << "The Holder Name is: " << name << endl;
        cout << "Current Balance: " << Balance << endl;
    } else {
        cout << "Account number not found.\n";
    }
}

int main() {
    AccountDetails p;
    int choice;
    long int AccNumber;

    while (true) {
        cout << "\n1. Add Details\n";
        cout << "2. Deposit Amount\n";
        cout << "3. Withdraw Amount\n";
        cout << "4. View Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.AddDetail();
                break;
            case 2:
                cout << "Enter your Account Number: ";
                cin >> AccNumber;
                p.DepositAmount(AccNumber);
                break;
            case 3:
                cout << "Enter your Account Number: ";
                cin >> AccNumber;
                p.WithdrawAmount(AccNumber);
                break;
            case 4:
                cout << "Enter your Account Number: ";
                cin >> AccNumber;
                p.ViewDetail(AccNumber);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
