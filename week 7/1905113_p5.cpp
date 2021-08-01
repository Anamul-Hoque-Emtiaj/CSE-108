#include <iostream>
using namespace std;


class inventory
{
    static int count;
public:
    inventory(){cout<<"Parameter-less constructor for inventory class object"<<endl;}
    inventory(int c){cout<<"Parameterized constructor for inventory class object"<<endl; count = c;}
    int get_count(){return count;}
    int set_count(int c){count = c;}
    void changeInventory(int c)
    {
        count = c;
    }
    void show()
    {
        cout<<"Available in Inventory: "<<count<<endl;
    }
    ~inventory(){cout<<"Destructor for inventory class object"<<endl;}
};

int inventory::count;

class buyer: public inventory
{
    static int buyItem;
public:
    buyer(){cout<<"Parameter-less constructor for buyer class object"<<endl;}
    buyer(int c):inventory(c){cout<<"Parameterized constructor for buyer class object"<<endl;}
    void changeInventory(int c)
    {
        buyItem+=c;
        set_count(get_count()+c);
        cout<<"So far bought quantity: "<<buyItem<<endl;
    }
    ~buyer(){cout<<"Destructor for buyer class object"<<endl;}
};

int buyer::buyItem;

///Write an appropriate definition of seller class.

class seller: public inventory
{
    static int sellItem;
public:
    seller(){cout<<"Parameter-less constructor for seller class object"<<endl;}
    seller(int c):inventory(c){cout<<"Parameterized constructor for seller class object"<<endl;}
    void changeInventory(int c)
    {
        set_count(get_count()-c);
        sellItem+=c;
        cout<<"So far sold quantity: "<<sellItem<<endl;
    }
    ~seller(){cout<<"Destructor for seller class object"<<endl;}
};

int seller::sellItem;

int main()
{
    int option, quantity, person;
    buyer b1, b2;
    seller s1, s2;
    cout<<"Enter option 1 to buy, option 2 to sell, and other to exit"<<endl;

    while(1)
    {
        cout<<"Option: ";
        cin>>option;
        if(option==1)
        {
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Person (1 or 2): ";
            cin>>person;
            if(person==1)
            {
                b1.changeInventory(quantity);
                b1.show();
            }
            else
            {
                b2.changeInventory(quantity);
                b2.show();
            }

        }
        else if(option == 2)
        {
            cout<<"Quantity: ";
            cin>>quantity;
            cout<<"Person (1 or 2): ";
            cin>>person;
            if(person==1)
            {
                s1.changeInventory(quantity);
                s1.show();
            }
            else
            {
                s2.changeInventory(quantity);
                s2.show();
            }
        }
        else
            break;
    }

    return 0;
}
