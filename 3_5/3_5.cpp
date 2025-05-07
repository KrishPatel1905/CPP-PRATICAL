#include<iostream>
using namespace std;

int CalculateSumOfD(int Number)
{
    int Sum = 0;

    while(Number > 0)
    {
        Sum += Number % 10;
        Number /= 10;
    }

    return Sum;
}

int CalculateSuperD(int Number)
{
    if(Number < 10)
    {
        return Number;
    }

    int Sum = 0;

    while(Number > 0)
    {
        Sum += Number % 10;
        Number /= 10;
    }

    return CalculateSuperD(Sum);
}

int main()
{
    int Num, NumRepeat;

    cout << "Enter number(n): ";
    cin >> Num;

    cout << "Enter the number of repetitions(k): ";
    cin >> NumRepeat;

    int Sum = CalculateSumOfD(Num);

    int TotalSum = Sum * NumRepeat;

    int SuperDigit = CalculateSuperD(TotalSum);

    cout << "Super digit: " << SuperDigit << endl;
    

    return 0;
}