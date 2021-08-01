/*******************************Offline 2****************************************/
/* Implement the functions of the class BookShop below as per the instructions  */
/* given inline the class definition. Make sure the output of the code in the   */
/* main function matches the given sample output. You may add/delete codes in   */
/* the main function during your testing. But before submission remove all your */
/* modifications from the main function and submit it as provided initially.    */
/********************************************************************************/

#include<iostream>
#include<cstring>
#include<cmath>
#include "Book.cpp"

using namespace std;

class BookShop{
	char name[100];
	Book* books; //List of books in the shop
	int size;  //maximum number of books the shop can keep
	int count; //tracks currently how many numbers in the shop
	public:
	    //setter function
		void setName(char* name){
		    strcpy(this->name,name);
		}

		void setSize(int size){
		    this->size=size;
		}
		void setCount(int count){
		    this->count=count;
		}

		//getter function
		char* getName(){
            return name;
		}
		int getSize(){
            return size;
		}
		int getCount(){
            return count;
		}

		BookShop(){//Default constructor
            strcpy(name,"");
            count=0;
            size=5;
            books= new Book[5];
		}

		BookShop(char* name, int size){//Parameterized constructor
            strcpy(this->name,name);
            count=0;
            this->size=size;
            books= new Book[size];
		}

		BookShop(const BookShop& bs){//Copy constructor
		    strcpy(name,bs.name);
		    size=bs.size;
		    count=bs.count;
		    books= new Book[bs.size];
		    for(int i=0;i<count;i++)
                books[i]=bs.books[i];
		}

		~BookShop(){//Destructor
            delete []books;
		}

		void addBook(Book b){
            books[count++]=b;

		}

		void addBook(Book* ba, int count){
            for(int i=0;i<count;i++)
            {
                books[(this->count)++]=ba[i];
            }
		}

		Book getBookInfo(char* title){
            for(int i=0;i<count;i++)
            {
                if(!strcmp(books[i].getTitle(),title))
                {
                    return books[i];
                    break;
                }
            }
		}

		void updateBookPrice(int isbn, int price){
            for(int i=0;i<count;i++)
            {
                if(books[i].getISBN()==isbn)
                {
                    books[i].setPrice(price);
                    break;
                }
            }
		}

		void removeBook(int isbn){
		    int in,i;
		    for(i=0;i<count;i++)
            {
                if(books[i].getISBN()==isbn)
                {
                    in=i;
                    break;
                }
            }
            for(i=in;i<count-1;i++)
                books[i]=books[i+1];
            count--;
		}

		int totalPrice(){
            int i,s=0;
            for(i=0;i<count;i++)
            {
                s+=books[i].getPrice();
            }
            return s;
		}

		void print(){
            cout<<"Bookshop Name: "<<name<<endl;
            for(int i=0;i<count;i++)
            {
                cout<<"ISBN: "<<books[i].getISBN()<<", Title: "<<books[i].getTitle()<<", Price: "<<books[i].getPrice()<<endl;
            }
		}

		BookShop mergeShop(BookShop b){
            BookShop temp("MergedShop",size+b.getSize());
            for(int i=0;i<count;i++)
            {
                temp.books[i]=books[i];
            }
            for(int i=0;i<b.getCount();i++)
            {
                temp.books[i+count]=b.books[i];
            }
            temp.setCount(count+b.getCount());
            return temp;
		}
};

int main(){

	BookShop bs1;
	bs1.setName("Boimela");
	Book b1(101,"Teach Yourself C++",100);
	Book b2(102,"Teach Yourself C",200);
	Book b3(103,"Java For Dummies",300);
	bs1.addBook(b1);
	bs1.addBook(b2);
	bs1.addBook(b3);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 102, Title: Teach Yourself C, Price: 200
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */
	cout<<endl;
	cout<<"Total price of books: "<<bs1.totalPrice()<<endl;	/*Output:
															   Total price of books: 600
															*/

	cout<<endl;
	bs1.removeBook(102);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 100
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	bs1.updateBookPrice(101,500);
	bs1.print(); /*Output:
					Bookshop Name: Boimela
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book jfd=bs1.getBookInfo("Java For Dummies");
	jfd.print();  /*Output:
					 ISBN: 103, Title: Java For Dummies, Price: 300
				 */

	cout<<endl;
	Book ba[3]={Book(201,"Operating Systems",1000),Book(202,"Compilers",2000),Book(203,"Computer Networks",1500)};
	BookShop bs2("Puthighor",5);
	bs2.addBook(ba,3);
	bs2.print();  /*Output:
					 Bookshop Name: Puthighor
					 ISBN: 201, Title: Operating Systems, Price: 1000
					 ISBN: 202, Title: Compilers, Price: 2000
					 ISBN: 203, Title: Computer Networks, Price: 1500
				 */

	cout<<endl;
	BookShop bs3=bs1.mergeShop(bs2);
	bs3.setName("Mullick Brothers");
	bs3.print(); /*Output:
					Bookshop Name: Mullick Brothers
					ISBN: 101, Title: Teach Yourself C++, Price: 500
					ISBN: 103, Title: Java For Dummies, Price: 300
					ISBN: 201, Title: Operating Systems, Price: 1000
					ISBN: 202, Title: Compilers, Price: 2000
					ISBN: 203, Title: Computer Networks, Price: 1500
				 */
}
