#include<iostream>
using namespace std;
int size;
template <class X>
class Stack
{
	X arr[30];
	int top;
	public:
		Stack()
		{
			for(int i=0; i<30;  i++)
				arr[i]=0;
			top=-1;
		}
		int isempty();
		void push(int);
		int pop();
		void clear();
		int topele();
		void display();
		int count();		
};

template <class X>
int Stack<X> :: isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;	
}

template <class X>
void Stack<X> :: push(int num)
{
	top++;
	arr[top]=num;
	display();
}

template <class X>
int Stack<X> :: pop()
{
	if(isempty()==1)
		cout<<"\nUnderflow";
	else
	{
		int x;
		x=arr[top];
		top--;
		return x;
	}
}

template <class X>
int Stack<X> :: topele()
{
	return arr[top];
}

template <class X>
void Stack<X> :: clear()
{
	if(isempty()==1)
	{
		cout<<"\nUnderflow";
	}
	else
	{
		cout<<"\nStack: \n";
		for(int i=0; i<=top; i++)
			pop();
	}
}

template <class X>
int Stack<X> :: count()
{
	int count=0;
	for(int i=0; i<=top; i++)
		count++;
	return count;
}

template <class X>
void Stack<X> :: display()
{
	cout<<"\nStack: \n";
	for(int i=0; i<=top; i++)
		cout<<arr[i]<<endl;
}

int main()
{
	Stack<int> s;
	int choice;
	cout<<"\nEnter size of array(less than 30): ";
	cin>>size;
	do
	{
		cout<<"\n\nMENU: \n";
		cout<<"\n1. Push";
		cout<<"\n2. Pop";
		cout<<"\n3. Top element";
		cout<<"\n4. Clear";
		cout<<"\n5. Display";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{   if(s.count()==size)
							cout<<"\nOverlfow";
						else
						{
						   	int data; 
					   		cout<<"\nEnter number: ";
					   		cin>>data;
					  		 s.push(data);
					  	}
					   break;
				   }
			case 2:{ if(s.isempty()==1)
						cout<<"\nUnderflow"	;
					else
						cout<<"\nDeleted element: "<<s.pop();
					break;
					}
			case 3:{ if(s.isempty()==1)
						cout<<"\nUnderflow";
					else
						cout<<"\nTop element: "<<s.topele();
					 break;
					}
			case 4: { s.clear(); break;	}
			case 5: { if(s.isempty()==1)
							cout<<"\nEmpty stack";
					  else
					  	s.display(); break; 
					}
			case 6: { exit(0);}
			default: { cout<<"\nWrong choice"; break; }
		}
	}while(choice!=6);
	return 0;
}
