#include<iostream>
#include<stdlib.h>
using namespace std;

class Random
{
    int **M,row,col,Mini,Maxi;
public:
    Random(int r,int c,int mn,int mx);
    ~Random();
    void print();
    void randomize();
    int get(int r,int c);
    void add(int v);
    int add();
};
Random :: Random(int r,int c,int mn,int mx)
{
    row=r;
    col=c;
    Mini=mn;
    Maxi=mx;
    M=(int**) malloc(row*sizeof(int*));
    for(int i=0; i<row; i++)
    {
        *(M+i)=(int*) malloc(col*sizeof(int));
    }
}
Random :: ~Random()
{
    for(int i=0; i<row; i++)
        free(*(M+i));
    free(M);
}
void Random :: print()
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            cout<<*(*(M+i)+j)<<" ";
        cout<<endl;
    }
}
void Random :: randomize()
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
            *(*(M+i)+j)=Mini+rand()%(Maxi-Mini);
    }
}
int Random :: get(int r,int c)
{
    return *(*(M+r)+c);
}
void Random :: add(int v)
{
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            *(*(M+i)+j)+=v;
    }
}
int Random :: add()
{
    int s=0;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
            s+=*(*(M+i)+j);
    }
    return s;
}
int main()
{
    cout<<"Hello World"<<'\n';
    Random m(3,3,100,200);
    m.randomize();
    m.print();
    cout<<m.get(0,0)<<'\n';
    m.add(100);
    m.print();
    cout<<m.add()<<'\n';
    return 0;
}
