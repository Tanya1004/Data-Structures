#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;

template <class X>
class LinkedList
{
	struct node
	{
		X data;
		node *prev, *next;
	}*first, *last;
	public:
		LinkedList()
		{
			first=NULL;
		}
		int isempty();
		void reverse();
		void insert_at_begin();
		void insert_at_end();
		void insert_at_loc();
		void del_at_begin();
		void del_at_end();
		void del_at_loc();
		int count();
		void search();
		void traverse();
		~LinkedList()
		{}
};
template <class X>
int LinkedList<X> :: isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}
template <class X>
void LinkedList<X> :: reverse()
{
	node *tempf=new node;
	tempf=first;
	while(tempf!=NULL)
	{
		node *tempn=new node;
		tempn=tempf->next;
		node *t=new node;
		t=tempf->next;
		tempf->next=tempf->prev;
		tempf->prev=t;
		tempf=tempn;
	}
	node *temp=new node;
	temp=first;
	first=last;
	last=temp;
	traverse();
}
template <class X>
void LinkedList<X> :: insert_at_begin()
{
	node * input=new node;
	input->prev=NULL;
	input->next=NULL;
	cout<<"\nEnter data: ";
	cin>>input->data;
	if(first==NULL)
	{
		first=last=input;
	}
	else
	{
		node *temp=new node;
		temp=first;
		input->next=temp;
		temp->prev=input;
		first=input;
	}
	traverse();
}
template <class X>
void LinkedList<X> :: insert_at_end()
{
	node *input=new node;
	input->prev=NULL;
	input->next=NULL;
	cout<<"\nEnter data: ";
	cin>>input->data;
	last->next=input;
	input->prev=last;
	last=input;
	traverse();
}
template <class X>
void LinkedList<X> :: insert_at_loc()
{
	int n=1, loc;
	cout<<"\nEnter location: ";
	cin>>loc;
	node *temp=new node;
	temp=first;
	if(loc==1)
		insert_at_begin();
	else
	{
		node *input=new node;
		input->prev=NULL;
		input->next=NULL;
		cout<<"\nEnter data: ";
		cin>>input->data;
		while(n<loc-1)
		{
			temp=temp->next;
			n++;
		}
		input->prev=temp;
		input->next=temp->next;
		temp->next->prev=input;
		temp->next=input;
		traverse();
	}
}
template <class X>
void LinkedList<X> :: traverse()
{
	node *temp=new node;
	temp=first;
	cout<<"\nList: ";
	while(temp!=NULL)
	{
		cout<<temp->data;

		if(temp->next!=NULL)
			cout<<"->";
		temp=temp->next;
	}
}
template <class X>
void LinkedList<X> :: del_at_begin()
{
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted element: "<<first->data;
		first=NULL;
	}
	else
	{
		cout<<"\nDeleted element: ";
		cout<<first->data;
		first=first->next;
		first->prev=NULL;
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
		cout<<"\nDeleted element: "<<first->data;
		first=NULL;
	}
	else
	{
		node *temp= new node;
		temp=last->prev;
		cout<<"\nDeleted element: ";
		cout<<last->data;
		temp->next=NULL;
		last=NULL;
		last=temp;
		traverse();
	}
}
template <class X>
void LinkedList<X> :: del_at_loc()
{
	int loc;
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else
	{
		cout<<"\nEnter location: ";
		cin>>loc;
		if(loc>count())
			cout<<"\nInvalid location!";
		else if(loc==1)
			del_at_begin();
		else if(loc==count())
			del_at_end();
		else
		{
			node *temp=new node;
			temp=first;
			node * temp1=new node;
			int count=1;
			while(count<loc-1)
			{
				temp=temp->next;
				count++;
			}
			temp1=temp->next;
			cout<<"\nDeleted element: "<<temp1->data;
			temp->next=temp1->next;
			temp1->next->prev=temp;
			delete temp1;
			traverse();
		}
	}
}
template <class X>
int LinkedList<X> :: count()
{
	node *temp=new node;
	temp=first;
	int count=1;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
template <class X>
void LinkedList<X> :: search()
{
	int num;
	node *temp=new node;
	temp=first;
	cout<<"\nEnter element to be searched: ";
	cin>>num;
	int flag=0;
	while(temp->next!=NULL)
	{
		if(temp->data==num)
			flag=1;
		temp=temp->next;
	}
	if(flag==0)
		cout<<"\nElement not found";
	else
		cout<<"\nElement found";
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
			case 1:{ l1.insert_at_begin(); break; }
			case 2:{ l1.insert_at_end(); break; }
			case 3:{ l1.insert_at_loc(); break; }
			case 4:{ l1.del_at_begin(); break; }
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
			case 10:{ l1.reverse(); break;}
			case 11:{ exit(0); }
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=11);
	getch();
}
