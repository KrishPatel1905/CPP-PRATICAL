#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

class Loan
{
    string Name;
    int Id;
    int Price;
    float Rate;
    float Time;

public:
    Loan()
    {
        Name = "Default Name";
        Id = 0;
        Price = 0;
        Rate = 0;
        Time = 0;
    }

    Loan(int id, string name, int price, int rate, int time)
    {
        Name = name;
        Id = id;
        Price = price;
        Rate = rate;
        Time = time;
    }

    void findEMI()
    {
        double Monthly_Interest = (Rate * 100) / 12;
        double EMI = (Price * Rate * (pow((1 + Monthly_Interest), Time))) / ((pow((1 + Monthly_Interest), Time)) - 1);
        cout << "Your EMI to pay : " << EMI << endl;
    }

    void showApplicantDetails()
    {
        cout << "\n======== Detail of Applicant : ========\n";
        cout << "Applicant Name : " << Name << endl;
        cout << "Applicant ID Number : " << Id << endl;
        cout << "Ammount for Loan : " << Price << endl;
        cout << "Duration of Loan : " << Time << endl;
        findEMI();
    }
} Detail[5];

int main()
{
    int i, Person, choice = 0;
    string name;

    cout << "\nEnter No. of person : ";
    cin >> Person;

    while (choice != 3)
    {
        cout << "\n1. For Enter The Data for Loan.\n";
        cout << "2. For Display EMI.\n";
        cout << "3. For Exit.\n";

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (i = 0; i < Person; i++)
            {
                int price, rate, time, id;
                cout << "\nEnter Detail of " << i + 1 << " Person : \n";

                cout << "Enter Name of Accountant : ";
                cin >> name;

                cout << "Enter id of Accountant : ";
                cin >> id;

                cout << "Enter Ammount : ";
                cin >> price;

                cout << "Enter Interest rate (%) : ";
                cin >> rate;

                cout << "Enter Loan months : ";
                cin >> time;

                Detail[i] = Loan(id, name, price, rate, time);
            }
            break;
        case 2:
            for (i = 0; i < Person; i++)
            {
                Detail[i].showApplicantDetails();
            }
            break;
        case 3:
            cout << "Exiting!!";
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
}
