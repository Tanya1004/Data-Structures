#include<iostream>
using namespace std;
int MAX=20, size;
class Queue
{
	int arr[20];
	int front, rear;
	public:
		Queue()
		{
			front=rear=-1;
		}
		void enqueue(int);
		int dequeue();
		int isempty();
		int firstel();
		void clear();
		void display();
};
void Queue :: enqueue(int num)
{
	if(isempty()==1)
	{
		front++;
		rear++;
		arr[front]=num;
	}
	else
	{
		rear++;
		arr[rear]=num;
	}
}
int Queue :: dequeue()
{
	int x=arr[front];
	front++;
	return x;
}
int Queue :: isempty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
int Queue :: firstel()
{
	return arr[front];
}
void Queue :: clear()
{
	if(isempty()==1)
		cout<<"\nEmpty Queue";
	else
	{
		while(front!=rear)
		{
			cout<<"\nDeleted element: "<<dequeue();
		}
		cout<<"\nDeleted element: "<<dequeue();
		front=rear=-1;
	}
}
void Queue :: display()
{
	cout<<"\nQueue";
	for(int i=front; i<=rear; i++)
	{
		cout<<"\n"<<arr[i];
	}
}
int main()
{
	Queue obj1; 
	int choice;
	cout<<"\nEnter size of Queue(less than 20): ";
	cin>>size;
	do
	{
		cout<<"\n\nMENU: \n";
		cout<<"\n1. Insert an element";
		cout<<"\n2. Delete an element";
		cout<<"\n3. Clear the Queue";
		cout<<"\n4. First element";
		cout<<"\n5. Display";
		cout<<"\n6. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{	if(rear==size-1)
							cout<<"\nOverflow";
						else
						{
							int data; 
							cout<<"\nEnter data: ";
							cin>>data;
							obj1.enqueue(data);
							obj1.display();
						}
						break;
					}
			case 2:{	if(obj1.isempty()==1)
							cout<<"\nUnderflow";
						else
						{
							int data;
							data=obj1.dequeue();
							cout<<"\nDelete element: "<<data;
						}
						break;
					}
			case 3:{	obj1.clear();
						break;
					}
			case 4:{	if(obj1.isempty()==1)
							cout<<"\nEmpty queue";
						else
							cout<<"\nFirst element: "<<obj1.firstel();
						break;
					}
			case 5:{	if(obj1.isempty()==1)
							cout<<"\nEmpty Queue";
						else
							obj1.display();
						break;
					}
			case 6:{	exit(0);	}
			default:{ 	cout<<"\nWrong choice";
						break;
					}
		}
	}while(choice!=6);
	return 0;
}
