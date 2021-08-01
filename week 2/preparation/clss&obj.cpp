#include<iostream>
using namespace std;

class Rectangle
{
    double *Height,*Width;
public:
    Rectangle()
    {
        Width=new double;
        Height=new double;
        *Width=0;
        *Height=0;
    }
    Rectangle(double a,double b);
    ~Rectangle()
    {
        delete Width;
        delete Height;
    }
    void setValue(double a,double b)
    {
        *Width=a;
        *Height=b;
    }
    double area();
};
Rectangle :: Rectangle(double a,double b)
{
    Width=new double;
    Height=new double;
    *Width=a;
    *Height=b;
}
double Rectangle :: area()
{
    return (*Height)*(*Width);
}
int main()
{
    Rectangle r1,r2(2.2,5.3);
    r1.setValue(2.2,5.3);
    cout<<"Area of r1 "<<r1.area()<<endl;
    cout<<"Area of r2 "<<r2.area()<<endl;
}
