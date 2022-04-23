#include <iostream>
#include<math.h>
#include <iostream>

using namespace std;
int evalPostfix(string Exp);


class Stack{
    public:
        int *top;
        int *str;
        int size,len;
    
        Stack()    //Constructor
        {
            top = NULL;
            // cout <<"Enter the limit of stack :  ";
            // cin>> 
            size=0;
            len = 0;
            cout <<endl;
            str = new int[size];
            
        }

      void push(int x)
        {
            if (top == NULL)
            {
                top=str;
                *top = x;
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
            len ++;
            return;
        
        
        }       // end of push function!


      void  pop(){
        if (len == 0)
            cout << "Stack Underflow!\n";
        else{
            *top = 0;
            top--;
            len--;
        }   
    
    }       //end of pop function
 
    char Top(){
            return *top;        //return the top value in the stack
        }

};

int main ()
{
    string postfixExp = "34*25*+";
    cout <<"Given Expression:   "<<postfixExp<<endl;

    cout <<"final Result:    "<<evalPostfix(postfixExp)<<endl;

    return 0;
}


int evalPostfix(string Exp)
        {
            
            Stack S;
            int len = Exp.length();
            S.size = len;       //difine the size of the stack

            for (int i = 0 ; i< len ; i++)
            {
                if (Exp [i] >= '0' && Exp [i] <= '9') {
                    S.push(Exp [i] - '0');      //only numbers will be pushed
                }
                else {

                    int x = S.Top();    //fetch first value
                    S.pop();

                    int y = S.Top();    //fetch secound value
                    S.pop();
                    

                    if (Exp [i] == '/') 
                        S.push(y / x);

                    else if (Exp [i] == '+') 
                        S.push(x+y);

                    else if (Exp [i] == '-') 
                        S.push(y - x);
                    
                    else if (Exp [i] == '*') 
                        S.push(x * y);

                    else if (Exp [i] == '^') 
                        S.push(pow(y, x));      //finding power 
                    
                }
            }
            
            return S.Top(); //final result which is in the stack will be our resul.
        }