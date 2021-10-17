#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next,*prev;


};

class Doubbly_ring_List 
{
    private:
        node *head,*temp,*temp1;
        int key;
    
    public:
        Doubbly_ring_List ()    //Constructor
        {
            head = temp = temp1 = NULL;
        }


        void insert ()
        {
            if (head == NULL)
            {
                head = new node ;
                cout <<"Enter the value: ";
                cin >>head ->info;
                head ->next = head ;
                head -> prev = head ;
                return ;
            }
            
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }

            temp1 = new node ;
            cout <<"enter the value for new node : ";
            cin >> temp->info;
            temp1 ->next =temp->next;
            temp ->next = temp1;
            temp -> prev = temp1;
            temp1 -> prev = temp;
    
            
        }


    void del()
    {
        if (head == NULL)
        {
            return;
        }
        else
        {
            cout <<"Enter the value you want to delete: ";
            cin>>key ;
        
            if (head ->info == key)
            {
                if (head ->next == head )
                {
                    delete(head);
                    head = nullptr;
                }

                head = head ->next;
                head ->prev = temp ->prev;
                head ->next = temp ->next;
                delete (temp);
                temp= nullptr; 
            }

            while (temp ->info != key)
            {
                temp = temp->next;
            }

            temp->next->prev = temp ->prev;
            temp ->prev->next = temp ->next;  

            delete(temp);
            temp= nullptr;

        }
        
    }


};

int main ()
{
    Doubbly_ring_List  obj;
    obj.insert();
    obj.insert();

    cout <<endl;
    
    obj.del();

    return 0;
}