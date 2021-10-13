#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next;


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
                
                return ;
            }
            
            temp = head;
            cout <<"Enter the value after which you add node:  ";
            cin >>key;

            while (temp != NULL )
            {

                if (temp->info == key )
                {

                    temp1 = new node;
                    cout<<"Enter the element: ";
                    cin >> temp1->info;

                    temp1->next = temp->next;
                    temp->next = temp1;

                    temp = temp->next;
                }
                temp = temp->next;
            }
        }//insert function ends here



    void del ()
    {
        cout <<"enter the value you want to delete :    ";
        cin >> key;
        cout << endl;

        if (head == NULL)
        {
            cout <<"list is empty"<<endl;
            return ;
        }
        temp = head;


        
        while (temp != NULL)
        {

            if (head->info == key)
                {
                    head = temp->next;
                    temp1 = temp; 
                    temp = temp->next;
                    delete(temp1);
                    temp1= nullptr;
                    return;
                }

           if (temp->next->info == key)
            {
            temp1 = temp->next;
            temp->next = temp->next->next ;
            
            delete(temp1);
            temp1= nullptr;

            if (temp->next != NULL){
            temp = temp->next;
            }
           
            }

            temp = temp->next;
            

        }
        
        

    }   //delete function ends here

    bool search ()
    {
        if (head == NULL)
        {
            cout<<"List is empty!";
            return 0;
        }
        temp = head;
        cout <<"enter value to search in list :  ";
        cin>>key;
        while(temp!=NULL)
        {
            
            if (temp->info == key )
            {
                cout <<"element has found in list"<<endl;
                return 1;
            }
            temp = temp->next;
        }
        if (temp ->info != key)
        {
            cout <<"list element does not found!";
        }


    }//search funtion has ended here


    void print ()
    {
        temp = head;
        while (temp != NULL )
        {
            cout <<temp->info<<"\t";
            temp = temp->next;
        }
        
    }


        
};

int main ()
{
	list obj; 

    //insetring the value in the node
    obj.insert();
    obj.insert();
    obj.insert();
    obj.insert();

    //print the valuesof the node
    obj.print();

    cout <<endl;
    //deleting nodes 
    obj.del();

    //again printing updated node
    obj.print();

    cout <<endl;
    //to searcch element in the list
    obj.search();

    cout<<endl;
	
	return 0;
}