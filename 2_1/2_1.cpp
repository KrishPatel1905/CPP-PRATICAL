#include<iostream>
using namespace std;
class PlotData
{
    int l;
    int w,Area,Parameter;
    public :
    void AddData();
    void UpdateData();
    void DisplayData();
};
void PlotData :: AddData()
{
cout<<"Enter the length :";
cin>>l;
cout<<"Enter the value  w :";
cin>>w;
Area=l*w;
Parameter=2*(l+w);
cout<<"The Area is : "<<Area;
cout<<"The parameter is  "<<Parameter;
}
void PlotData ::UpdateData()
{
    cout<<"Enter the length :";
    cin>>l;
    cout<<"Enter the value  w :";
    cin>>w;
    Area=l*w;
    Parameter=2*(l+w);
    cout<<"The Area is : "<<Area;
    cout<<"The parameter is  "<<Parameter;
}
void PlotData ::DisplayData()
{
    cout<<"The plot lenght is "<<l<<endl;
    cout <<"The plot  width os "<<w<<endl;
    cout <<"The Aera is "<<Area<<endl;
    cout <<"The parameter is "<<Parameter;
} 
int main()
{
    
    PlotData p[25];
    int choice,c=0,NumPlot,i;
    
   next : cout<<"1.Add data \n"<<"2.Update Data \n"<<"3. Display Data"<<endl;
   cout<<"Enter the choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
        p[c].AddData();
        c++;
        break;
        case 2:
        cout<<"Enter the plot number  :";
        cin>>NumPlot;
        if(NumPlot<=c)
        {
            p[NumPlot-1].UpdateData();
        }
        else{
            cout<<"The total ploat is :"<<c;
        }
        break;
        case 3 :
        {
           for( i=0;i<c;i++)
           {
            p[i].DisplayData();
           }
           break;
        }
        default :
        {
            goto d;
            break;
        }

    }
    goto next;
        d :return 0;

}