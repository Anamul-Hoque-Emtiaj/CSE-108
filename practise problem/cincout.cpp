#include<iostream>
using namespace std;

class Vector
{
    double x,y,z;
public:
    Vector() {}
    Vector(double x,double y,double z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
    friend ostream &operator<<(ostream &out, Vector v);
    friend istream &operator>>(istream &in, Vector &v);
    friend Vector operator*(int n, Vector v);
};

ostream &operator<<(ostream &out, Vector v)
{
    out<<"X: "<<v.x<<endl;
    out<<"Y: "<<v.y<<endl;
    out<<"Z: "<<v.z<<endl;
    return out;
}
istream &operator>>(istream &in, Vector &v)
{
    cout<<"Enter X"<<endl;
    in>>v.x;
    cout<<"Enter Y"<<endl;
    in>>v.y;
    cout<<"Enter Z"<<endl;
    in>>v.z;
    return in;
}

Vector operator*(int n, Vector v)
{
    Vector temp;
    temp.x=v.x*n;
    temp.y=v.y*n;
    temp.z=v.z*n;
    return temp;
}

int main()
{
    Vector v,mult;
// Overload >> operator to take Vector input
    cin>>v;
// Perform scalar multiplication of v and store it into mult
// v should be unchanged after multiplication.
    mult=5*v;
// Overload << operator to perform Vector output.
    cout<<v;
    cout<<mult;
    return 0;
}
