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
		void enqueue(int);
		int dequeue();
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
void Stack :: enqueue(int ele)
{
	Node *temp = new Node;
	temp->data=ele;
	temp->next=top;
	top=temp;
}
int Stack :: dequeue()
{
	Node *ptr=new Node;
	ptr=top;
	int x;
	x=ptr->data;
	top=top->next;
	delete ptr;
	return x;
}
void Stack :: display()
{
	if(isempty()==1)
		cout<<"\nEmpty queue";
	else
	{
		Node *temp=new Node;
		temp=top;
		cout<<"\nQueue: \n";
		while(temp!=NULL)
		{
			cout<<temp->data<<"\n";
			temp=temp->next;
		}
	}
}
int main()
{
	Stack s1, s2;
	int choice;
	do
	{
		cout<<"\n\nMENU: \n";
		cout<<"\n1. Insert an element";
		cout<<"\n2. Delete an element";
		cout<<"\n3. Display Queue";
		cout<<"\n4. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{	int num;
						cout<<"\nEnter element: ";
						cin>>num;
						if(s1.isempty()==1)
							s1.enqueue(num);
						else
						{
							while(s1.isempty()!=1)
							{
								int x;
								x=s1.dequeue();
								s2.enqueue(x);
							}
							s1.enqueue(num);
							while(s2.isempty()!=1)
							{
								int z;
								z=s2.dequeue();
								s1.enqueue(z);
							}
						}
						s1.display();
						break;
					}
			case 2:{	if(s1.isempty()==1)
						{
							cout<<"\nEmpty Queue";
						}
						else
						{
							cout<<"\nDeleted element: "<<s1.dequeue();
						}
						cout<<"\nQueue after Deletion: ";
						s1.display();
						break;
					}
			case 3:{	s1.display();
						break;
					}
			case 4:{	exit(0);	}
			default:{	cout<<"\nWrong choice";
						break;
					}
		}
	}while(choice!=4);
	return 0;
}
