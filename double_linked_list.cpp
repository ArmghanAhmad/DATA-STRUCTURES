#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next, *prev;


};

class list 
{
    private:
        node *head,*temp,*temp1;
        int key;
    
    public:
        list()    //Constructor
        {
            head = temp = temp1 = NULL;
        }

    void insert()
        {
            if (head  == NULL)
            {
                head = new node;
                cout <<"enter the first value :    ";
                cin >> head->info ;
                head->prev = NULL;
                head ->next = NULL;
                
                return ;
            }
            temp = head;

            cout <<"Enter the value after which you add node:  ";
            cin >>key;

            while (temp != NULL  )
            {

                if (temp->info == key )
                {
                    temp1 = new node;
                    cout<<"Enter the element: ";
                    cin>>temp1->info;

                    temp1->next = temp ->next;
                    temp1->prev = temp;
                    if(temp1->next != NULL)
                    {
                        temp1->next->prev = temp->next;
                    }
                    temp->next= temp1;
    
                }
                temp = temp->next;
            }
        }

    void del ()
    {
        if (head == NULL)
        {
            return ;
        }
        temp = head;
        
            cout <<"Enter the value you want to delete: ";
            cin>>key ;
        
            if (head -> info == key)
            {
                if (head -> next == NULL)
                {
                    delete(head);
                    head = nullptr;
                }
                head = head ->next;
                head ->prev = NULL ;
                delete (temp);
                temp= nullptr; 
            }
        
            while (temp != NULL)
            {
                if (temp ->next-> info == key)
                {
                    temp1 = temp->next;
                    temp->next = temp ->next ->next ;
                    temp1->next =temp;
                    delete(temp1);
                    temp1 =nullptr;
                    
                    return;

                }
                temp = temp ->next;
            }//while ended here
        
        

    }       //function delete ended here

    void print ()
    {
        if (head != NULL)
        {
            temp = head ;

            while (temp != NULL)
            {
                cout <<temp ->info<<"  ";
                temp = temp ->next;
            }
            cout <<endl;
        }
        else
        {
            cout <<"List is empty."<<endl;
        }
        
    }

    void search ()
    {
        cout << "Enter the value you want to search: ";
        cin >> key;

        
        temp = head;

        while (temp != NULL)
        {
            if (temp ->info == key)
            {
                cout <<"value has founded in the list!..";
                return;
            }
           temp = temp->next;
        }
        if (head == NULL)
        {
            cout <<"List is empty !...";
        }
        else
        {
            cout <<"LIST is EMPTY";
        }
        
        

    }

        
};

int main ()
{
	list obj; 
    obj.insert();
	obj.insert();
    obj.insert();
    
    cout <<endl;
    
    obj.print();
    cout <<endl;
    
    obj.del();
    
    cout <<endl;
    
    obj.print();
    
    cout <<endl;
    
    obj.search();
    cout <<endl;

	return 0;
}
