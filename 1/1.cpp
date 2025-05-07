  /*Design a simple class BankAccount to represent a bank account. It should have
the following:
Attributes:
o Account holder's name, account number, and balance.
Methods:
o deposit(amount): to add money to the account.
o withdraw(amount): to deduct money from the account if sufficient balance
exists. Otherwise, print an error message.
o display_balance() to show the current balance.
Requirements:
o Demonstrate object-oriented principles: encapsulation and abstraction.
o Test the class by creating multiple accounts and performing operations.*/

#include<iostream>
using namespace std;
class BankAccount
{
   private :
   char HolderName[25];
   long int AccountNumber;
   double balance;
   public :
   void InsertData()
   {
    cout<<"Enter the HolderName : ";
    cin>>HolderName;
    cout<<"Enter the Account Number : ";
    cin>>AccountNumber;
    cout<<"your Balance is ";
    cin>>balance;
   }
   void Deposite(double x)
   {
    
     balance=balance+x;
     cout<<"Your current balnace is "<<balance<<endl;
   }
   void withdraw(double y)
   {
       if(y<=balance)
       {
      balance=balance-y;
       }
       else 
       {
        cout<<"sufficient balance is not availble ";
       }
   } 
   void Display()
   {
      cout<<"Your current balance is : "<<balance<<endl;
   }
};
   int main()
   {
    double depo;
    double draw;
    class BankAccount A[2];
    for(int i=0;i<2;i++)
    {
      A[i].InsertData();
    }
    for(int i=0;i<2;i++)
    {
      cout<<" the deposite Ammount : ";
      cin>>depo;
      A[i].Deposite(depo);
    }
    for(int i=0;i<2;i++)
    {
      cout<<"Enter the withdraw ammout : ";
      cin>>draw;
      A[i].withdraw(draw);
    }
    for(int i=0;i<2;i++)
    {
      A[i].Display();
    }
   }


