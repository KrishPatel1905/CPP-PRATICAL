#include<iostream>
using namespace std;
class com 
{
  protected :
  int m1,m2,m3;
  float per;
  public :
  virtual void grade()=0;
};
class ug :public com
{
     public :
     void getdata()
     { 
        cout<<".......... MARKS OF UG ..........."<<endl;
        cout<<"Enetr the mark 1 :";
        cin>>m1;
        cout<<"Enetr the mark 2 :";
        cin>>m2;
        cout<<"Enetr the mark 3 :";
        cin>>m3;
        per=(m1+m2+m3)/3;
        cout<<"Your pertanges is :"<<per<<endl;
     }
     void grade()
     {
        if(45<per && per<=100)
        {
            cout<<"Pass"<<endl;
        }
        else if (100<per)
        {
            cout<<"Invaild per"<<endl;
        }
        else {cout<<"Fail";}
     }
};
class pg :public com
{
     public :
     void getdata()
     {
        cout<<"..........MARKS OF PG .........."<<endl;
        cout<<"Enetr the mark 1 :";
        cin>>m1;
        cout<<"Enetr the mark 2 :";
        cin>>m2;
        cout<<"Enetr the mark 3 :";
        cin>>m3;
        
        per=(m1+m2+m3)/3;
        cout<<"Your pertanges is :"<<per<<endl;
     }
     void grade()
     {
        if(55<per && per<=100)
        {
            cout<<"Pass"<<endl;
        }
        else if (100<per)
        {
            cout<<"Invaild per"<<endl;
        }
        else {cout<<"Fail";}
     }
};
using namespace std;
int main()
{
    ug u;
    pg p;
    u.getdata();
    u.grade();
    p.getdata();
    p.grade();
    
    
    return 0;
}