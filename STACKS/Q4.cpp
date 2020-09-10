#include<iostream>
using namespace std;
class Stack
{
	struct Node
	{
		int data;
		Node *next;
	}*top;
	public:
		Stack()
		{
			top=NULL;
		}
		int isempty();
		void push(int);
		int pop();
		void clear();
		int topel();
		void display();
		~Stack()
		{
			delete top;
		}
};
int Stack :: isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
void Stack :: push(int num)
{
	Node *temp = new Node;
	temp->data=num;
	temp->next=top;
	top=temp;
	display();
}
int Stack :: pop()
{
	Node *ptr=new Node;
	ptr=top;
	int x;
	x=ptr->data;
	top=top->next;
	delete ptr;
	return x;
}
void Stack :: clear()
{
	if(isempty()==1)
		cout<<"\nUnderflow";
	else
	{
		cout<<"\nElements of Stack were: \n";
		while(isempty()!=1)
		{
			cout<<pop()<<"\n";
		}
		cout<<"\nNow the stack is empty";
	}
}
int Stack :: topel()
{
	return top->data;
}
void Stack :: display()
{
	if(isempty()==1)
		cout<<"\nEmpty stack";
	else
	{
		Node *temp=new Node;
		temp=top;
		cout<<"\nStack: \n";
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			temp=temp->next;
		}
	}
}
int main()
{
	Stack s;
	int choice;
	do
	{
		cout<<"\n\nMENU: ";
		cout<<"\n1. Push";
		cout<<"\n2. Pop";
		cout<<"\n3. Clear";
		cout<<"\n4. Top element";
		cout<<"\n5. Display";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ int num;
					 cout<<"\nEnter number: ";
					 cin>>num;
					 s.push(num);
					 break;
					}
			case 2:{ if(s.isempty()!=1)
						cout<<"\nDeleted element: "<<s.pop();
					else
						cout<<"\nUnderflow";	
					 break;	}
			case 3:{ s.clear(); break;	}
			case 4:{ if(s.isempty()!=1)
						cout<<"\nTop element: "<<s.topel();
					else
						cout<<"\nUnderflow"; 
					 break;	}
			case 5:{ s.display(); break; }
			case 6:{ exit(0); }
			default:{ cout<<"Wrong choice";	break;	}
		}
	}while(choice!=6);
	return 0;
}
