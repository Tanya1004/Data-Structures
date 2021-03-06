#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;

//Circular Singly LL
template <class X>
class Queue
{
	struct node
	{
		int info;
		node *next;
	}*front, *rear;
	public:
		Queue<X>()
		{
			front = rear = NULL;
		}
		~Queue<X>()
		{}
		void traverse();
		int isempty();
		void enqueue();
		void dequeue();
		int firstel();
		void clear();
};

template <class X>
int Queue<X> :: firstel()
{
	return front->info;
}

template <class X>
void Queue<X> :: clear()
{
	if(isempty()==0)
		cout<<"\nUnderflow";
	else
	{
		while(front!=NULL)
		{
			dequeue();
		}
	}
}
template <class X>
void Queue<X> :: traverse()
{
	if(isempty()==0)
		cout<<"\nEmpty Queue";
	else
	{
		cout<<"\nQueue: \n";
		node * temp=new node;
		temp=front;
		while(temp!=rear)
		{
			cout<<temp->info;
			if(temp!=rear)
				cout<<" -> ";
			temp=temp->next;
		}
		if(temp==rear)
			cout<<temp->info;
	}
}

template <class X>
int Queue<X> :: isempty()
{
	if(front==NULL)
		return 0;
	else
		return 1;
}

template <class X>
void Queue<X> :: enqueue()
{
	node * input=new node;
	cout<<"\nEnter data: ";
	cin>>input->info;
	input->next=NULL;
	
	if(isempty()==0)
	{
		front=rear=input;
		rear->next=front;
	}
	else
	{
		rear->next = input;
		input->next=front;
		rear=input;
	}
	traverse();
}

template <class X>
void Queue<X> :: dequeue()
{
	if(isempty()==0)
		cout<<"\n No elements in queue";
	else if(front==rear)
	{
		cout<<"\nDeleted Element : "<<front->info;
		front=rear=NULL;
	}
	else
	{
		node *temp=new node;
		temp=front;
		cout<<"\nDeleted element: ";
		cout<<front->info;
		rear->next=front->next;
		front=front->next;
		traverse();
	}
}

int main()
{
	Queue<int> l1;
	int choice;
	cout<<"\n\tCircular Queue using Linked List\n";
	do
	{
		cout<<"\n\nMENU: \n";
		cout<<"\n1. Enqueue";
		cout<<"\n2. Dequeue";
		cout<<"\n3. Display";
		cout<<"\n4. First element";
		cout<<"\n5. Clear";
		cout<<"\n6. Exit";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ l1.enqueue(); break; }
			case 2:{ l1.dequeue(); break; }
			case 3:{ l1.traverse(); break; }
			case 4:{ int x=l1.firstel(); 
					 cout<<"\nFirst eleent: "<<x;
					 break; 
					}
			case 5:{ l1.clear(); 
					 break;
					}
			case 6:{ exit(0);	}
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=6);
	return 0;
}
