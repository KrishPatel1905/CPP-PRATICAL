#include<iostream>
#include<set>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of tran :";
    cin>>n;
    set<int>tran;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int id;
        cin>>id;
       tran.insert(id); 
    }
    for (int id :tran )
    {
        /* code */
            cout<<id<<" ";
    }
    
    

}