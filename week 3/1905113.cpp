#include <iostream>
#include<cmath>
using namespace std;
class Point
{
    // x and y coordinate
    int x, y;
public:
    Point(int X,int Y)
    {
        x=X;
        y=Y;
    }
    Point()
    {
    }
    void set(int X,int Y)
    {
        x=X;
        y=Y;
    }
    int getx()
    {
        return x;
    }
    int gety()
    {
        return y;
    }
    void print()
    {
        cout << "Coordinate: "<< x <<", " <<y <<endl;
    }
};
class Circle
{
    Point p;
    int radius;
public:
    Circle(int X,int Y,int r)
    {
        p.set(X,Y);
        radius=r;
    }
    void update(int r)
    {
        radius+=r;
    }
    void update(int X,int Y)
    {
        p.set(p.getx()+X,p.gety()+Y);
    }
    void update(int X,int Y,int r)
    {
        p.set(p.getx()+X,p.gety()+Y);
        radius+=r;
    }
    void print()
    {
        cout << "Center ";
        p.print();
        cout << "Radius: " << radius << endl;
    }
};
class Line
{
    Point p1,p2;
public:
    Line(int a1, int b1, int a2, int b2)
    {
        p1.set(a1,b1);
        p2.set(a2,b2);
    }
    int length()
    {
        return sqrt(pow(p1.getx()-p2.getx(),2)+pow(p1.gety()-p2.gety(),2));
    }
};
int main()
{
    Point p(5,5);
    Circle c(2, 3, 5);
    cout << endl << "Point Display" <<endl;
    p.print();
    cout << endl << "Circle Display" <<endl;
    c.print();
    cout << endl;
    //First update
    cout << "First Update" << endl;
    c.update(5,5);
    c.print();
    cout <<endl;
    //Second update
    cout << "Second Update" << endl;
    c.update(6);
    c.print();
    cout << endl;
    //Third update
    cout << "Third Update" << endl;
    c.update(2,2,2);
    c.print();
    cout << endl;

    //new added class Line
    Line l(0,0,3,4);
    cout<<"Length Display"<<endl;
    cout<<"Length : "<<l.length()<<endl;
    return 0;
}
