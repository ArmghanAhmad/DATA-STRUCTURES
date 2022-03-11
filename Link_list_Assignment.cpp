#include <iostream>
using namespace std;

struct node {
    int info ;
    node * next;
};

class Link_List 
{
    public:
        node *head ,*temp ,*temp1;
        int key , length ;

    Link_List ()
    {
        temp = temp1 = curr = head = NULL;
        length = 0;
    }

    //function for Tail
    void Tail (){
        temp = head ;
        while (temp->next != NULL)
        {
            temp = temp -> next;
        }
    }

    //function for Head
    void Head (){
        if (head != NULL)
        {
            temp = head;
        }
        else{
            cout<<"LIST is empty!";
            return ;
        }
    }

    // function for Length
    int Length ()
    {
        return length;
    }

    //function too find list is Full or empty

    void  Full (){
        if (head != NULL){
            cout <<"list contain "<<length<<" elements."<<endl;
            return;
        }
        else {
            cout <<"List is empty"<<endl;
            return ;
        }
    }

    //function for search 
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


    }
    
    //printing funtion
    void print ()
    {
        if (head == NULL){
            cout <<"List is empty!";
            return;
        }
        else{
            temp = head;
            while (temp != NULL )
            {
                cout <<temp->info<<"\t";
                temp = temp->next;
            }
        }
    }

                //insert function
    void insert()
        {
            if (head  == NULL)
            {
                head = new node;
                cout <<"enter the first value :    ";
                cin >> head->info ;
                head ->next= NULL;
                length++;
                
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
                    length ++;

                    temp1->next = temp->next;
                    temp->next = temp1;

                    temp = temp->next;
                }
                temp = temp->next;
            }
        }//insert function ends here


                    // Delete function
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
                    length--;
                    return;
                }

           if (temp->next->info == key)
            {
            temp1 = temp->next;
            temp->next = temp->next->next ;
            
            delete(temp1);
            temp1= nullptr;
            length--;

            if (temp->next != NULL){
            temp = temp->next;
            }
           
            }

            temp = temp->next;
            

        }
        
        

    }   //delete function ends here

    //swapping function

    void Swapping ()
    {
        temp =temp1= head ;
        int pos = length;
        int current=0;

        if (head == NULL)
        {
            cout <<"List is empty!"<<endl;
            return ;
        }
        //cout <<"length: "<<length<<"position: "<<pos<<endl;
        for (int i = 0; i < length/2 ; i++){
            
            for (int j=0 ; j < pos - 1 ; j++){
                temp = temp->next;
            }
            
            current = temp1->info;
            temp1->info = temp->info;
            temp->info = current;
            
            temp1 = temp1->next;
            pos--;
            temp=head;
        }
        
    }

};

int main ()
{
    Link_List obj;

    obj.insert();
    obj.insert();
    obj.insert();
    obj.insert();
    obj.insert();
cout <<"You entered list:"<<endl;

    obj.print();
    cout<<endl;

    obj.Swapping();
cout <<"List After swapping:"<<endl;
    obj.print();
    cout<<endl;

    return 0;
}