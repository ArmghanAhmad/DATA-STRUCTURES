#include <iostream>
using namespace std;


class Stack 
{
    private:
        int *top;
        int *str;
        int size;
    
    public:
        Stack()    //Constructor
        {
            top = NULL;
            cout <<"Enter the limit of stack :  ";
            cin>> size;
            cout <<endl;
            str = new int[size];
            
        }

        void push()
        {
            if (top == NULL)
            {
                top=str;
                cout <<"ENTER FIRST VALUE IN STACK : ";
                cin>>*top;
                // *top=1;
                cout <<endl;
                return;
            }
            

            if (str+(size-1) == top)
            {
                cout <<"Stack overflow";
                return ;
            }
            top++;
            cout<<"ENTER THE VALUE :    ";
            cin >>*top;
            // *top=2;
            cout <<endl;
            return;
        }

        void pop()
        {
            
            if (top == NULL)
            {
                cout <<"STACK UNDERFLOW"<<endl;
                return;
            }
            
            if (top == str)
            {
                top= NULL;
                return;
            }
            top--;
            return;
        }

        void print ()
        {
            
            if (top== NULL)
            {
                cout <<"UNDERFLOW!..."<<endl;
            }
            while (top != NULL )
            {
                cout <<*top<<"\t";
                pop();
            }
        } 


};

int main ()
{
    Stack obj;
    obj.push();
    obj.push();
    obj.push();
    obj.push();
    cout <<endl;

    obj.print();
    cout <<endl;

    obj.pop();
    cout <<endl;

    obj.print();
    cout <<endl;



    return 0;
}