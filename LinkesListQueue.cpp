#include<iostream>
using namespace std;
class Queue
{
	struct Node
	{
		int data;
		Node *next;
	}*front, *rear;
	public:
		Queue()
		{
			front=rear=NULL;
		}
		void clear();
		int isempty();
		void enqueue(int);
		int dequeue();
		int firstel();
		void display();
		~Queue()
		{ }
};
int Queue :: isempty()
{
	if(front==NULL)
		return 1;
	else
		return 0;
}
void Queue :: enqueue(int num)
{
	Node * ptr=new Node;
	ptr->data=num;
	ptr->next=NULL;
	if(isempty()==1)
	{
		front=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
int Queue :: dequeue()
{	
	int info;
	info=front->data;
	front=front->next;
	return info;
}
void Queue :: clear()
{
	if(isempty()==1)
		cout<<"\nUnderflow";
	else
	{
		while(front!=NULL)
		{
			int x=dequeue();
			cout<<"\nDeleted element: "<<x;
		}
	}
}
int Queue :: firstel()
{
	return front->data;
}
void Queue :: display()
{
	if(isempty()==1)
	{
		cout<<"\nEmpty Queue";
	}
	else
	{
		Node * ptr=new Node;
		ptr=front;
		cout<<"\nQueue";
		while(ptr!=NULL)
		{
			cout<<"\n"<<ptr->data;
			ptr=ptr->next;
		}
	}
}
int main()
{
	int choice;
	Queue obj1;
	do
	{
		cout<<"\n\nMENU: \n";
		cout<<"\n1. Insert an element";
		cout<<"\n2. Delete an element";
		cout<<"\n3. Clear the queue";
		cout<<"\n4. First element";
		cout<<"\n5. Display queue";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: { 	int num;
						cout<<"\nEnter element: ";
						cin>>num;
						obj1.enqueue(num);
						obj1.display();
						break;
					}
			case 2: {	if(obj1.isempty()==1)
							cout<<"\nUnderflow";
						else
						{
							cout<<"\nDeleted element: "<<obj1.dequeue();
						}
						break;
					}
			case 3: {	obj1.clear();
						break;
					}
			case 4: {	if(obj1.isempty()==1)
							cout<<"\nUnderflow";
						else
							cout<<"\nFirst element: "<<obj1.firstel();
						break;
					}
			case 5:{	obj1.display();
						break;
					}
			case 6:{	exit(0);	}
			default:{ cout<<"\nWrong choice";	break;	}
		}
	}while(choice!=6);
	return 0;
}
