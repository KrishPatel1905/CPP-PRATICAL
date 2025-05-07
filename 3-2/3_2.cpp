#include<iostream>
using namespace std;
int RecursiveSum(int arr[],int n)
{
 if(n<=0)
 {
     return 0;
 }
    return RecursiveSum(arr,n-1)+arr[n-1];
}
int IterativeSum(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
   
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int recursivesum=RecursiveSum(arr,n);
    int iterativesum=IterativeSum(arr,n);
    cout<<"Your Recursive sum is : "<<RecursiveSum<<endl;
    cout<<"Your Iterative sum is : "<<IterativeSum<<endl;
    return 0;
}