#include<iostream>
#include<cstring>
using namespace std;

namespace infrastructure{
    class pool{
        int height, width, depth;
        char painted_color[10];
    public:
        void set_properties(int h, int w, int d, char *pc)
        {
            height=h;
            width=w;
            depth=d;
            strcpy(painted_color,pc);
        }
        void show()
        {
            cout<<"Dimention: "<<height<<" X "<<width<<" X "<<depth<<endl;
            cout<<"painted_color: "<<painted_color<<endl;
        }
    };
}

namespace sports{
    class pool{
        char table_ingredient[20];
        char table_color[10];
    public:
        void set_properties(char *ti, char* tc)
        {
            strcpy(table_ingredient,ti);
            strcpy(table_color,tc);
        }
        void show()
        {
            cout<<"table_ingredient: "<<table_ingredient<<endl;
            cout<<"table_color: "<<table_color<<endl;
        }
    };
}

int main()
{
    infrastructure::pool p1;
    sports::pool p2;
    p1.set_properties(1,2,3,"Blue");
    p2.set_properties("wood","red");
    p1.show();
    p2.show();
}
