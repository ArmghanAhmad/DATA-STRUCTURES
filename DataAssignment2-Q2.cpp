#include <iostream>
#include<math.h>

using namespace std;
class Stack 
{
    private:
        int *top;
        int *str;
        int size,len;
    
    public:
        Stack()    //Constructor
        {
            top = NULL;
            // cout <<"Enter the limit of stack :  ";
            // cin>> 
            size=50;
            len = 0;
            cout <<endl;
            str = new int[size];
            
        }

        void push(char x)
        {
            if (top == NULL)
            {
                top=str;
                *top = x;
                // *top=1;
                len ++;
                return;
            }
            

            if (str+(size-1) == top)
            {
                cout <<"Stack overflow";
                return ;
            }
            top++;
            *top = x;
            // *top=2;
            len ++;
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
            len--;
            return;
        }

        char Top(){
            return *top;
        }

       void print ()
        {
        	int *temp;
        	temp = str;
            
            if (top== NULL)
            {
            	return;
                cout <<"UNDERFLOW!..."<<endl;
            }
           for (int i =0 ; i < len ; i++)
            {
                cout <<*temp<<"\t";
                temp++;
				
            }
        }

        bool isEmpty () {
		if (top == NULL)
            {
                return true;
            }
			else 
			{
				return false;
			}   
            
        }


};

bool BalanceBracket (string Exp, int len)
        {
            Stack S;
            char ch;
            
            for (int i = 0 ; i< len ; i++)
            {
                if (Exp [i] == '[' || Exp [i] == '{' || Exp[i]=='(') {
                    S.push(Exp [i]);

                }
                else if(S.isEmpty() == true) {
                    return false;
                } 
                else {

                    if (Exp [i] == ')') {

                        ch = S.Top();
                        S.pop();
                        if (ch == '[' || ch=='{'){
                            return false;
                        }
                        break;
                    }

                    else if (Exp [i] == ']') {

                        ch = S.Top();
                        S.pop();
                        if (ch == '(' || ch=='{'){
                            return false;
                        }
                        break;
                    }

                    else if (Exp [i] == '}') {

                        ch = S.Top();
                        S.pop();
                        if (ch == '[' || ch=='('){
                            return false;
                        }
                        break;
                    }

                }
            }
            
            return S.isEmpty();
        }

int main ()
{
    string postfixExp = "{()[]" ;
    cout <<"Given Expression:   "<<postfixExp<<endl;
    int len = postfixExp.length();

   if (BalanceBracket(postfixExp, len ) == true){
       cout <<"Expression is  Balanced!"<<endl;
   }
   else{
       cout <<"Expression is not Balanced"<<endl;
   }

   cout <<endl;
   cout <<endl;


   string postExp = "[] ()" ;
    cout <<"Given Expression:   "<<postExp<<endl;
    int slen = postExp.length();

   if (BalanceBracket(postExp, slen ) == true){
       cout <<"Expression is  Balanced!"<<endl;
   }
   else{
       cout <<"Expression is not Balanced"<<endl;
   }
    return 0;
}