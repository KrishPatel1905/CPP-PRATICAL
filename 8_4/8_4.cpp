#include<iostream>
using namespace std;
int main()
{
    float loanamount,income,ratio;
    cin>>loanamount;
    cin>>income;
    try{
        if(loanamount>income)
        {
            throw "Sorry Your Income is nit sufficiat";
        }
        else{
            ratio=loanamount / income;
            cout<<"Your loan ratio :"<<ratio;
        }
    }
    catch(const char *msg)
    {
        cout<<"!!ERROR :!!"<<msg;
    }
    return 0;
}