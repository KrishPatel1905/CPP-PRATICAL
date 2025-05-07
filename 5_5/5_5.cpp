#include<iostream>
using namespace std;
class Shape
{
    public :
    virtual float  Area()=0;
};
class Rectangel :public Shape
{
    float w ,l,a;
    public :
    void GetData()
    {
        cout<<"Enter the value of w :";
        cin>>w;
        cout<<"enter the value of l :";
        cin>>l;
        cout<<endl;
    }
    float Area()
    {
        a=l*w;
        cout << "Area of Rectangle: " << a<< endl;
    }
    
};
class Circle :public Shape
{
    float r,a;
    public :
    void GetData()
    {
        cout<<"Enter the value of r :";
        cin>>r;
        cout<<endl;
    }
    float Area()
    {
        a=r*r;
        cout << "Area of  Circle " << a << endl;
    }

};

int main()
{
    Rectangel rect;
    Circle cir;
    rect.GetData();
    cir.GetData();
    Shape *shape;
    shape = &rect;
    shape->Area();
   shape =&cir;
   shape->Area(); 
   
    return 0;
}