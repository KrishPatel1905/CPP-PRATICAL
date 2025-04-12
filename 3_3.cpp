#include <iostream>
using namespace std;

class MoneySystem {
    char HolderName[25];
    long int balance;
    int AccNum = 0;
    int aNum;

public:
    void AddAccount() {
        cout << "Enter the holder Name : ";
        cin >> HolderName;
        cout << "Enter the deposit Amount: ";
        cin >> balance;
        AccNum++;
        cout << "Your Bank Account number is : " << AccNum << endl;
    }

    void DepositAmount() {
        cout << "Enter the Account number : ";
        cin >> aNum;
        int DepoAmounnt;
        if (aNum == AccNum) {
            cout << "Enter the Deposit Amount : ";
            cin >> DepoAmounnt;
            balance = balance + DepoAmounnt;
            cout << "Now your Bank Balance is : " << balance << endl;
        }
    }

    void WithDraw() {
        int WithAmount;
        cout << "Enter the Account number : ";
        cin >> aNum;
        if (aNum == AccNum) {
            cout << "Enter the Withdraw Amount : ";
            cin >> WithAmount;
            balance = balance - WithAmount;
            cout << "Now your Bank Balance is : " << balance << endl;
        }
    }

    void Transper() {
       
    }
};

int main() {
    MoneySystem m;
d:
    cout << "1. Add Account\n2. Deposit Amount\n3. Withdraw Amount\n4. Transfer Money Account\n";
    int choice;
    cout << "Enter the choice which you want : ";
    cin >> choice;
    switch (choice) {
        case 1:
            m.AddAccount();
            break;
        case 2:
            m.DepositAmount();
            break;
        case 3:
            m.WithDraw();
            break;
        case 4:
            m.Transper();
            break;
        default:
            cout << "Invalid Choice !! Please Enter the Right Choice." << endl;
            goto d;
    }
    goto d;
    return 0;
}
