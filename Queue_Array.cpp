#include <iostream>
using namespace std;

class Queue
{                           //Pehli ka back null hota
                           //Last ka next null hota

    private:
        int *Qarr,*temp;
        int *front,*back ;
        int size;
    
    public:
        Queue ()    //Constructor
        {
            front = back= NULL;
            cout <<"Enter the Size of array of Queue :  ";
            cin>> size;
            cout <<endl;
            Qarr =new int [size];
        }

        void enqueue()
        {
            if (front ==NULL)
            {
            front= back= temp = Qarr;
            cout <<"Enter value :   ";
            cin >> *front ;
            cout <<endl;

            return;
            }
            if (back+1== front)
               {
                cout <<"Queue is FULL!.."<<endl;
                return;
               }
            if (front == Qarr  && back==(Qarr + (size-1)))
            {
                cout <<"Queue is FULL!.."<<endl;
                return;
            }
            if (front != Qarr  && back==(Qarr + (size-1)))
            {
                back = Qarr;     
                cout <<"Enter the next value :  ";
                cin >>*back ;
                //   *back =2;
                return;
            }
            back++;
            cout <<"Enter the next value :  ";
            cin >>*back ;
            cout <<endl;
            
            return;
        }

        void dequeue()
        {
            if (front == NULL)
            {
                cout <<"Queue is Empty!"<<endl;
                return ;
            }
            if (front == back )
            {
                front = back = NULL;
                cout<<"Queue is empty!"<<endl;
                return;
            }
            if (front == Qarr +(size-1))
            {
                front = Qarr;
                cout <<"Queue is empty!.."<<endl;
                return;
            }
            
            front ++;
            return;
        }


        void print ()
        {
            if (front == NULL)
                {
                    cout <<"Queue is Empty."<<endl;
                    return;
                }

            temp=front;

            while (true)
            {
                cout <<*temp<<" ";
                if (temp == back)
                {
                    break;
                }
                if (temp == Qarr +(size-1))
                {
                    if (temp == back)
                    {
                        break;
                    }
                    temp = Qarr;
                }
                else
                {
                    temp ++;
                }
            }
            

        }

};

int main ()
{
    Queue obj;
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    obj.enqueue();
    
    
    
    cout<<endl;
    obj.print();
    
    cout<<endl;
    obj.dequeue();
    cout<<endl;
    obj.print();
    cout <<endl;
    return 0;
}