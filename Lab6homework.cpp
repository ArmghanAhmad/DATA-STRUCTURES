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
        node *head,*temp,*temp1,*temp2;
        int key;
    
    public:
        Doubbly_ring_List ()    //Constructor
        {
            head = temp = temp1 = temp2 = NULL;
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

    void split (){
        temp = temp1 =temp2 = head ;
        int len=0;

        while (temp2->next != head ){
            temp2 = temp2 -> next; 
            len++;
        }
            temp = head;
        for (int i = 0; i < len /2; i++)
        {
            temp = temp ->next;
            temp1 = temp ->next;
        }

        temp -> next = head ;
        head ->prev = temp ;

        temp2 ->next = temp1;
        temp ->prev = temp2;
        
        return;
    }

    void reverse (){
            temp = head ;
            while (temp != head){
                temp = temp->next;
            }
            head = temp;

            return;
    }

    void Duplicates(){
        temp = temp1 = temp2 = head;
        int Dkey, len;

        while (temp2->next != head ){
            temp2 = temp2 -> next; 
            len++;
        }
        cout << "Enter key you want to delete:"<<endl;
        cin >>Dkey;
        // for (int i =0 ; i<len;i++){

            while (temp-> next != head ){
                
                if (head ->info == Dkey)
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

                    while (temp ->info != Dkey)
                    {
                        temp = temp->next;
                    }

                    temp->next->prev = temp ->prev;
                    temp ->prev->next = temp ->next;  

                    delete(temp);
                    temp= nullptr;
                }
            // }
        
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
