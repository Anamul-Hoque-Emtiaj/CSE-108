#include<iostream>
#include<stdlib.h>
using namespace std;

class Matrix
{
    int **M,*row,*col;
public:
    Matrix(int r,int c);
    ~Matrix();
    void print();
    void set(int r,int c,int v);
    int get(int r,int c);
    void add(int v);
    int add();
};
Matrix :: Matrix(int r,int c)
{
    *row=r;
    *col=c;
    M=(int**) malloc((*row)*sizeof(int*));
    for(int i=0; i<(*row); i++)
    {
        *(M+i)=(int*) malloc((*col)*sizeof(int));
    }
}
Matrix :: ~Matrix()
{
    for(int i=0; i<(*row); i++)
        free(*(M+i));
    free(M);
}
void Matrix :: print()
{
    for(int i=0; i<(*row); i++)
    {
        for(int j=0; j<(*col); j++)
            cout<<*(*(M+i)+j)<<endl;
        cout<<endl;
    }
}
void Matrix :: set(int r,int c,int v)
{
    *(*(M+r)+c)=v;
}
int Matrix :: get(int r,int c)
{
    return *(*(M+r)+c);
}
void Matrix :: add(int v)
{
    for(int i=0; i<(*row); i++)
    {
        for(int j=0; j<(*col); j++)
            *(*(M+i)+j)+=v;
    }
}
int Matrix :: add()
{
    int s=0;
    for(int i=0; i<(*row); i++)
    {
        for(int j=0; j<(*col); j++)
            s+=*(*(M+i)+j);
    }
    return s;
}
int main()
{
    cout<<"Hello World"<<'\n';
    Matrix m(3,3);
    for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
            m.set(i,j,i+j);
    m.print();
    cout<<m.get(0,0)<<'\n';
    m.set(0,0,100);
    cout<<m.get(0,0)<<'\n';
    m.add(100);
    m.print();
    cout<<m.add()<<'\n';
    return 0;
}
