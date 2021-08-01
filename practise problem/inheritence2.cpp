#include<iostream>
using namespace std;

class Stack
{
protected:
    int buffer[100];
    int top;
public:
    void init()
    {
        top=0;
    }
    int getSize()
    {
        return top;
    }
    void push(int item)
    {
        if(getSize()>=100){
            cout<<"Stack Full"<<endl;
        }
        else{
            buffer[top++]=item;
        }
    }
    int pop()
    {
        if(getSize()<=0){
            cout<<"Stack Empty"<<endl;
            return NULL;
        }
        else{
            int temp;
            temp=buffer[top];
            top--;
            return temp;
        }
    }
    bool isEmpty()
    {
        if(getSize()==0)
            return true;
        else
            return false;
    }
    void print()
    {
        for(int i=0;i<top;i++)
        {
            cout<<buffer[i]<<" ";
        }
        cout<<endl;
    }
};

class Queue: public Stack
{
    int tail;
public:
    void init()
    {
        tail=0;
        top=0;
    }
    int getSize()
    {
        return top-tail;
    }
    void enqueue(int item)
    {
        push(item);
    }
    int deque()
    {
        if(getSize()<=0){
            cout<<"Stack Empty"<<endl;
            return NULL;
        }
        else
        {
            int temp = buffer[tail];
            buffer[tail]=NULL;
            tail++;
            return temp;
        }
    }
    bool isEmpty()
    {
        if(getSize()==0)
            return true;
        else
            return false;
    }
    void print()
    {
        for(int i=tail;i<top;i++)
        {
            cout<<buffer[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Queue q;
    q.init();
    cout<<"Size "<<q.getSize()<<endl;
    cout<<"isEmpty "<<q.isEmpty()<<endl;
    for(int i=0;i<3;i++){
        q.enqueue(i+1);
        q.push(i+11);
    }
    q.print();
    cout<<"Size "<<q.getSize()<<endl;
    cout<<"isEmpty "<<q.isEmpty()<<endl;
    q.pop();
    q.pop();
    cout<<"pop"<<endl;
    q.print();
    q.deque();
    q.deque();
    cout<<"deque"<<endl;
    q.print();
}
