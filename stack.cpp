#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next;
};

class Stack 
{
    private:
        node *head,*temp;
        int counter,limit;
    
    public:
        Stack()    //Constructor
        {
            head = temp = NULL;
            counter =0;
            cout <<"Enter the limit of stack :  ";
            cin>> limit;
        }

        void push()
        {
            if (counter == limit){
                cout <<"stack over flows"<<endl;
                return ;
            }
            
            else if (head == NULL){
                head = new node;
                cout <<"ENTER Value :  ";
                cin >> head ->info;
                cout <<endl;
                head ->next = NULL;
                counter ++;
                return;
            }

            else
            {
                temp = new node ;
                cout <<"ENTER value of New node = ";
                cin >>temp->info;
                cout <<endl;
                temp -> next = head;
                head = temp;
                counter++;
                return;
            }

        
        }

        void pop ()
        {
            if (head == NULL)
            {
                cout <<"stack is already empty. there is nothing to delete...."<<endl;
                return;
            }
            if (head->next==NULL)
            {
                head = temp = NULL;
                cout <<"stack is empty. there is nothing to delete...."<<endl;
                return;
            }
            temp = head;
            head = head ->next;
            delete(temp);
            temp = head;    
            counter --;
            
        }

        void print ()
        {
            temp = head;
            if (head == NULL)
            {
                cout <<"STACK UNDERFLOW! "<<endl;
                return;
            }
            temp = head;
            while (temp != NULL )
            {
                cout <<temp->info<<"\t";
                temp = temp->next;
            }
        
    

        }

        void top()
        {
            cout <<"TOP ELEMENT OF THE LIST = "<<temp -> info;
        }

};

int main ()
{

    Stack obj;

    obj.push();
    obj.push();
    obj.push();
    obj.push();
    obj.push();
    cout <<endl;



    cout <<"\n"<<endl;

    cout <<"Stack before poping!"<<endl;

    obj.print();
    cout <<endl;
    
    obj.pop();

    cout <<endl;
    cout <<"Stack after poping!"<<endl;

    obj.print();
    cout <<endl;

    return 0;

}