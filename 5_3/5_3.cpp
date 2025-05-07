#include<iostream>
using namespace std;
class point
{
    int x,y;
public:
    void insert_data()
    {
        cout<<"Enter x:";
        cin>>x;
        cout<<"Enter y:";
        cin>>y;
    }

    point operator-()
    {
        point a;
        a.x=-x;
        a.y=-y;
        return a;
    }
    point operator+(point &k)
    {
        point b;
        b.x=x+k.x;
        b.y=y+k.y;
        return b;

    }
    bool operator==(point p3)
    {
        return (x == p3.x && y == p3.y);
    }
    void display()
    {
        cout<<x<<endl;
        cout<<y<<endl;
    }
};
int main()
{
    point p1,p2,p3;
    p1.insert_data();
    p2=-p1;
    p2.display();
    p2.insert_data();
    p3=p1+p2;
    p3.display();
    if (p2 == p3) {
        cout << "Yes, Equal\n";
    } else {
        cout << "No, Not Equal\n";
    }

}