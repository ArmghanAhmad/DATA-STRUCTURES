#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next,*pre;
};

class Queue
{                           //Pehli ka back null hota
                           //Last ka next null hota

    private:
        node *front,*back,*temp;
        int counter,limit;
    
    public:
        Queue ()    //Constructor
        {
            front = back=temp= NULL;
            counter =0;
            cout <<"Enter the limit of stack :  ";
            cin>> limit;
            cout <<endl;
        }

        void enqueue() //Add hamesha end se ho ga
        {                             
            if (counter == limit)
            {
                cout << "Queue is overflows!.."<<endl;
                return;
            }

            if (front == NULL)
            {
                front = new node ;
                front ->next = front ->pre= NULL;
                cout<< "Enter first value :   "<<endl;
                cin >> front -> info;
                back= front;
                counter++;
                return;
            }

            back= new node;
            cout <<"Enter new value!..."<< endl;
            cin>>back->info;
            temp->next = back->next;
            back->next = temp;
            back= back->next;
            return;

        }

        void dequeue ()
        {
            if (front == NULL)
            {
                cout <<"Queue underflows!.."
                return;
            }

            if (front->next = NULL)
            {
                front = back = temp= NULL;
                cout <<"Queue is empty now!..."<<endl;
                return;
            }
            back=front;

            front =front->next;
            delete(back);
            back=NULL;
            return;
        }



};

int main ()
{
    Queue obj;

    obj.enqueue() ;
    obj.enqueue() ;
    obj.enqueue() ;
    obj.enqueue() ;

    cout <<endl;
    return 0;
}