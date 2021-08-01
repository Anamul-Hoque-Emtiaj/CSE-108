#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
        cout<<name<<" Constractor\n";
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
        cout<<name<<" Constractor\n";
    }

    int setX(int a){x=a;}
    int setY(int b){y=b;}
    int setZ(int c){z=c;}

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX(){return x;}
    int getY(){return y;}
    int getZ(){return z;}

    char *getName(){return name;}

    ~Vector()
    {
        cout<<name<<" destractor\n";
        delete []name;
    }
    void print()
    {
        cout<<name<<": ";
        if(x!=0)
            cout<<x<<"x";
        if((x==0||y<0)&&y!=0)
            cout<<y<<"y";
        else if(y>0)
            cout<<"+"<<y<<"y";
        if(((x==0&&y==0)||z<0)&&z!=0)
            cout<<z<<"z";
        else if(z>0)
            cout<<"+"<<z<<"z";
        cout<<endl;
    }
    Vector operator^(Vector &v)
    {
        Vector temp("temp");
        temp.x=y*v.z-z*v.y;
        temp.y=z*v.x-x*v.z;
        temp.z=x*v.y-y*v.x;
        return temp;
    }
    Vector &operator=(const Vector &v)
    {
        cout<<name<<" Assingment\n";
        x=v.x;
        y=v.y;
        z=v.z;
        return *this;
    }
    int operator==(Vector &v)
    {
        if(x==v.x&&y==v.y&&z==v.z)
            return 1;
        else return 0;
    }
    friend Vector operator*(Vector &V1,Vector &V2);
    friend Vector operator*(int n,Vector &V);
    friend Vector operator*(Vector &V,int n);
};

Vector operator*(Vector &V1,Vector &V2)
{
    Vector temp("temp");
    temp.x=V1.x*V2.x;
    temp.y=V1.y*V2.y;
    temp.z=V1.z*V2.z;
    return temp;
}
Vector operator*(int n,Vector &V)
{
    Vector temp("temp");
    temp.x=n*V.x;
    temp.y=n*V.y;
    temp.z=n*V.z;
    return temp;
}
Vector operator*(Vector &V,int n)
{
    Vector temp("temp");
    temp.x=n*V.x;
    temp.y=n*V.y;
    temp.z=n*V.z;
    return temp;
}

int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    v1.print();     ///Print the components of vector v1
    v2.print();     ///Print the components of vector v2

    v3=v1^v2;       ///Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       ///Multiply each component of vector v1 with the given value
    v1.print();     ///Print the modified components of vector v1

    v2=2*v2;        ///Multiply each component of vector v2 with the given value
    v2.print();     ///Print the modified components of vector v2

    v3=v1*v2;     ///Multiply each component of vector v1 with the corresponding component of vector v2.
    v3.print();     ///Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      ///Check for equality; if two vectors contain equal component values (x, y, z), then they are equal.
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}

