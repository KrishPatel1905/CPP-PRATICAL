#include<iostream>
using namespace std;

class DigitTool
{
public:
    int digitSum(string strNum)
    {
        int result = 0;
        for (char ch : strNum)
        {
            result += ch - '0';
        }
        return result;
    }

    int finalSuperDigit(string strNum, int times)
    {
        long long tempSum = (long long)digitSum(strNum) * times;
        if (tempSum < 10)
        {
            return tempSum;
        }
        else
        {
            return finalSuperDigit(to_string(tempSum), 1);
        }
    }
};

int main()
{
    string numInput;
    int repeatNum;
    cout << "Enter the Number as a string: ";
    cin >> numInput;
    cout << "Enter the Number of times you want to repeat the number : ";
    cin >> repeatNum;

    DigitTool obj;
    cout << "The Super Digit of " << numInput << " is : " << obj.finalSuperDigit(numInput, repeatNum) << endl;
    return 0;
}
