#include <iostream>
using namespace std;

class Array{
	
	private:
		int *arr;
		int max,len,*current,*temp;
	public:

	Array(){
		len = 1;
		max=10;
		arr =new int [10];
		current=temp=arr;
		
	}
	 
		 
		 bool empty(){
		 	if (arr == NULL){
		 		cout <<"Array is empty!.."<<endl;
		 		return 1;
			 }
			 else 
			 {
			 	 cout <<"There are elements in array."<<endl;
			 	 return 0;
			 }
		 }	
		 
    	bool full(){
		 	if (arr != NULL){
		 		cout <<"Array is Full!.."<<endl;
		 		return 1;
			 }
			 else 
			 {
			 	 cout <<"Array is empty"<<endl;
			 	 return 0;
			 }
		 }		 	


	//function for insert element
	void insertElement (int value , int pos )
		{
	 	cout<<"position is :"<<pos<<endl;
		cout<<"length is: "<<len<<endl;

		if(pos > max || pos <= 0){
			cout<<"index/position out of bounds"<<endl;
			return;
		}
		if((len == 0 && pos != 1) || (len != 0 && pos > len+1)){
			
			cout<<"Invalid position!!!!";
			return;
		}

		// else
		// {
			current=arr;
		
			
			for(int i=1;i<=pos;i++){
			current++;
			}
			
			if(pos ==  len+1){		//position base inserting
				*current=value;
				len++;
				return;
			}

			for(int i=1;i<=len;i++){
				temp++;
			}

			while(temp>=current){
				*(temp+1)=*temp;
				temp--;
			}

			*current=value; 		//inserting at end of array
			len++;
		//}

	}
	
	void remove(int pos){
	
	current=arr;

	for(int i=1;i<=pos;i++){
	
	current++;
	}

	temp=current;

	for(int i=pos-1;i<len;i++){
	*temp=*(temp+1);
	temp++;
	}

	len--;
	}


	bool find(int value){
	
		bool chk=0;
		temp=arr;


		for(int i=0;i<len;i++){
		if(*temp==value){
			chk=1;
			cout <<*temp<< "Value fonded!";
			return chk; 
			}
		}

		
	}
	void reverse ( ){

		current= arr+1;

		temp= arr+(len-1);

		int s = len / 2;
		int swap;

		for (int i= 1; i<=s; i++){
			swap = *current;
			*current = *temp;
			*temp = swap;

			current++;
			temp--;
		}
		cout <<endl;
	}


	int get(int pos){
		temp=arr;
		
		for(int i=1;i<=pos;i++){
			temp++;
		}
		return *temp;
	}

	void emptylist (){
	
		temp=arr;

		for(int i=0;i<len;i++){
		*temp=0;
		temp++;
		}

	len=0;
	}
	
	int length(){
	return len;
	}

};

int main ()
{
	Array arr1;
	int num; // number of element you want to enter
	
	//insert from start of index
	cout <<"Enter number of element you want to enter (1 - 10) : ";
	cin>>num;

	cout<<"Inserting Element"<<endl;
	for(int i =1; i<= num; i++){
		cout <<"Enter value: "<<endl;
		int x= 0;
		cin>>x;

		arr1.insertElement(x,i);
	}


	
 	cout<<"\nYou enter array : "<<endl;
	//print value 
	for(int i =1; i<= num; i++){
		
		cout<<arr1.get(i)<<"\t";
	}
	
	arr1.reverse();
	cout <<"\nArray after swaping:"<<endl;
	//print value 
	for(int i =1; i<= num; i++){
		
		cout<<arr1.get(i)<<"\t";
	}
	int index;
	cout <<"\nEnter index to remove: ";
	cin>>index;
	cout<<endl;
	arr1.remove(index);
	cout<<"\nYou array after removing  : "<<endl;

	//print value 
	for(int i =1; i<= num; i++){
		
		cout<<arr1.get(i)<<"\t";
	}

	


	return 0;
}
