#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;

//Circular Singly LL
template <class X>
class LinkedList
{
	struct node
	{
		int info;
		node *next;
	}*first;
	public:
		LinkedList<X>()
		{
			first= NULL;
		}
		~LinkedList<X>()
		{}
		void traverse();
		int isempty();
		void insert_at_beg();
		void insert_at_end();
		void insert_at_loc();
		void del_at_beg();
		void del_at_end();
		void del_at_loc();
		void search();
		void reverse();
		int count();
};
template <class X>
void LinkedList<X> :: traverse()
{
	cout<<"\nList: \n";
	node * temp=new node;
	temp=first;
	while(temp->next!=first)
	{
		cout<<temp->info;
		if(temp->next!=first)
			cout<<" -> ";
		temp=temp->next;
	}
	if(temp->next==first)
		cout<<temp->info;
}
template <class X>
int LinkedList<X> :: isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}
template <class X>
void LinkedList<X> :: insert_at_beg()
{
	node *input=new node;
	cout<<"\nEnter data: ";
	cin>>input->info;
	input->next=NULL;
	if(first==NULL)
	{
		first=input;
		first->next=first;
	}
	else
	{
			node *temp=new node;
			temp=first;
			input->next=first;
			while(temp->next!=first)
			{
				temp=temp->next;
			}
			temp->next=input;
			first=input;
	}
	traverse();
}
template <class X>
void LinkedList<X> :: insert_at_end()
{
	node * input=new node;
	cout<<"\nEnter data: ";
	cin>>input->info;
	input->next=NULL;
	node *temp=new node;
	temp=first;
	while(temp->next!=first)
		temp=temp->next;
	input->next=temp->next;
	temp->next=input;
	traverse();
}
template <class X>
void LinkedList<X> :: insert_at_loc()
{
	int loc;
	cout<<"\nEnter location: ";
	cin>>loc;
	if(loc==1)
		insert_at_beg();
	else
	{
		node * temp=new node;
		node * input=new node;
		temp=first;
		cout<<"\nEnter data: ";
		cin>>input->info;
		input->next=NULL;
		int num=1;
		while(num<loc-1)
		{
			temp=temp->next;
			num++;
		}
		input->next=temp->next;
		temp->next=input;
		traverse();
	}
}
template <class X>
void LinkedList<X> :: del_at_beg()
{
	if(isempty()==0)
		cout<<"\n No elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted Element : "<<first->info;
		first=NULL;
	}
	else
	{
		node *temp=new node;
		temp=first;
		cout<<"\nDeleted element: ";
		cout<<first->info;
		while(temp->next!=first)
			temp=temp->next;
		temp->next=first->next;
		first=first->next;
		traverse();
	}
}
template <class X>
void LinkedList<X> :: del_at_end()
{
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted Element : "<<first->info;
		first=NULL;
	}
	else
	{
		node * temp=new node;
		temp=first;
		while((temp->next)->next!=first)
		{
			temp=temp->next;
		}
		cout<<"\nDeleted element: ";
		cout<<(temp->next)->info;
		temp->next = first;
		traverse();
	}
}
template <class X>
void LinkedList<X> :: del_at_loc()
{
	int loc;
	node * temp=new node;
	temp=first;
	if(isempty()==0)
		cout<<"\nNo elements in list";

	else
	{
		cout<<"\nEnter location: ";
		cin>>loc;

		if(loc>count())
			cout<<"\nInvalid location!";
		else if(loc==1)
			del_at_beg();
		else if(loc==count())
			del_at_end();
		else
		{
			int num=1;
			while(num<loc-1)
			{
				temp=temp->next;
				num++;
			}
			node * temp1=new node;
			temp1=temp->next;
			cout<<"\nDeleted element: "<<temp1->info;
			temp->next=temp1->next;
			delete temp1;
			traverse();
		}
	}
}
template <class X>
void LinkedList<X> :: reverse()
{
	node *tempf=new node;
	node *templ=new node;
	tempf=first;
	templ=first;
	while(templ->next!=first)
		templ=templ->next;
	while((tempf->next)->next!=first)
	{
		while((tempf->next)->next!=first)
			tempf=tempf->next;
		(tempf->next)->next=tempf;
		tempf->next=first;
		tempf=first;
	}
	first->next=templ;
	first=templ;
	cout<<"\nReversed list: ";
	traverse();
}
template <class X>
void LinkedList<X> :: search()
{
	int num;
	cout<<"\nEnter number to be serched: ";
	cin>>num;
	node * temp=new node;
	temp=first;
	int flag=0;
	while(temp->next!=first)
	{
		if(temp->info==num)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==0)
		cout<<"\nElement not found";
	else
		cout<<"\nElement found";
}
template <class X>
int LinkedList<X> :: count()
{
	node * temp=new node;
	temp=first;
	int n=1;
	while(temp->next!=first)
	{
		n++;
		temp=temp->next;
	}
	return n;
}
int main()
{
	LinkedList<int> l1;
	int choice;
	do
	{
		cout<<"\n\nMENU: ";
		cout<<"\n1. Insert at beginning";
		cout<<"\n2. Insert at end";
		cout<<"\n3. Insert at location";
		cout<<"\n4. Delete at beginning";
		cout<<"\n5. Delete at end";
		cout<<"\n6. Delete at location";
		cout<<"\n7. Search";
		cout<<"\n8. Count";
		cout<<"\n9. Display";
		cout<<"\n10. Reverse";
		cout<<"\n11. Exit";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ l1.insert_at_beg(); break; }
			case 2:{ l1.insert_at_end(); break; }
			case 3:{ l1.insert_at_loc(); break; }
			case 4:{ l1.del_at_beg(); break; }
			case 5:{ l1.del_at_end(); break; }
			case 6:{ l1.del_at_loc(); break; }
			case 7:{ l1.search(); break; }
			case 8:{ if(l1.isempty()==0)
					cout<<"\nEmpty list";
				else
					cout<<"Number of elements: "<<l1.count();
				break;
				}
			case 9:{ l1.traverse(); break; }
			case 10:{l1.reverse(); break; }
			case 11:{ exit(0); }
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=11);
	getch();
}
