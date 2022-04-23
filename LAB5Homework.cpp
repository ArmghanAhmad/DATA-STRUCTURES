#include <iostream>
using namespace std;
struct node 
{
    int info;
    node *next;


};

class list 
{
    public:
        node *head,*temp,*temp1,*current;
        int sum =0, average =0,lenght =0 , len =0, key;
    
    
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
                lenght++;

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
                    lenght++;

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
                    lenght--;

                    return;
                }

           if (temp->next->info == key)
            {
                temp1 = temp->next;
                temp->next = temp->next->next ;
                
                delete(temp1);
                temp1= nullptr;
                lenght--;

                if (temp->next != NULL){
                    temp = temp->next;
                }
           
            }

            temp = temp->next;
            

        }
        
        

    }   //delete function ends here

// search function
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

// pint funnction
    void print ()
    {
        temp = head;
        while (temp != NULL )
        {
            cout <<temp->info<<"\t";
            temp = temp->next;
        }
        
    }

    void tail(){
        temp = head;
        while (temp-> next != NULL){
            temp = temp->next;
        }
    }

    int Lenght (){
        return lenght;
    }

    void Lhead(){
        temp = head;
    }
//Summing and Averaging Elements in a List
    int Average (){
        temp = head;

        if (head == NULL){
            cout <<"List is empty!"<<endl;
            return 0;
        }
        while (temp->next != NULL){
            sum += temp->info;
            len ++;
            temp = temp->next;
        }
        average= sum/len;

        return average;
    } //Summing and Averaging Elements in a List ends here


//insert values at the middle of a Single Linked List.
    void midInsert(){

        temp = temp1 =head;

        if (head == NULL)
        {
            cout <<"List is empty!"<<endl;
            return ;
        }
        else{#include <iostream>
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
            for (int i = 1 ; i<lenght/2 ; i++){
                temp = temp->next;
            }
            temp1 = new node;
            cout<<"Enter the center element: ";
            cin >> temp1->info;
            lenght++;

            temp1->next = temp->next;
            temp->next = temp1;
        }

    } // middle function ends here

    void Swapping (){
        temp = temp1 = current = head;
        if (head == NULL )
        {
            cout <<"List is empty!"<<endl;
            return ;
        } 
        while (temp != NULL)
        {
            temp = current->next;
            temp1 = current->next;
            temp1 =current;
            current = temp;
        }
        head = temp1;
    }

    void reverse (){
        temp =temp1 = head ;
        if (head == NULL )
        {
            cout <<"List is empty!"<<endl;
            return ;
        }
        while (temp1->next != NULL)
        {
            temp = temp1;
            temp1 = temp1->next;
        }
        temp ->next = NULL;

        temp1->next = head;
        head = temp1;


    }

    // Linked List the Palindrome

    void CheackPalindrome (){
        temp = temp1 = current = head;
        if (head == NULL )
        {
            cout <<"List is empty!"<<endl;
            return ;
        } 
        while (temp != NULL)
        {
            temp = current->next;
            temp1 = current->next;
            temp1 =current;
            current = temp;
        }
        head = temp1;
    }



// Remove Duplicates
    void RemoveDuplicates (){
        temp = head ;
        if (head == NULL)
        {
            cout <<"List is empty!"<<endl;
            return ;
        }
        cout <<"enter the value you want to delete :    ";
        cin >> key;
        cout << endl;

        for (int i=0; i<lenght ; i++)
        {
            if (head->info == key)
                {
                    head = temp->next;
                    temp1 = temp; 
                    temp = temp->next;
                    delete(temp1);
                    temp1= nullptr;
                    lenght--;

                    return;
                }

           if (temp->next->info == key)
            {
                temp1 = temp->next;
                temp->next = temp->next->next ;
                
                delete(temp1);
                temp1= nullptr;
                lenght--;
           
            }

            temp = temp->next;
        }
    }

    
        
};

int main ()
{
    int Concatenation=0;
	list obj ,obj2; 
    cout <<"Enter 1 for Concatenation or 0 to skip :  " ;
    cin>>   Concatenation;
    cout<<"\n"<<endl;
    //insetring the value in the node
    obj.insert();
    obj.insert();
    obj.insert();
    obj.insert();
    //print the valuesof the node
    obj.print();

    cout <<endl;


    // cout <<"deleting "<<endl;

    // obj.RemoveDuplicates ();

    // obj.print();
    // cout <<endl;
    // cout <<"Enter Value of Secound list" <<endl;
    // obj2.insert();
    // obj2.insert();
    // obj2.insert();
    // obj2.insert();

    // //print the valuesof the node
    // obj2.print();

// Concatenating Lists

    if (Concatenation == 1)
    {
        node *temp,*temp1 ;
        temp = obj.head;
        temp1 = obj2.head;

        while (temp ->next != NULL)
        {
            temp = temp->next;
        }
        
        temp->next = temp1;
    }

    cout <<"Swaping first and last node value"<<endl;
    obj.reverse();
//print the valuesof the node
    obj.print();

    cout <<endl;
    cout <<"inserting the middle node!"<<endl;
    obj.midInsert();
    
    obj.print();
    cout <<endl;


	
	return 0;
}