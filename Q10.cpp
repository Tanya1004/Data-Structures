#include<iostream>
#include<process.h>
#include<conio.h>
using namespace std;

template <class t>
class LinkedList
{
	struct node
	{
		t info;
		node *next;
	}*first, *last;
	
	public:
		LinkedList()
		{
			first= NULL;
		}
		~LinkedList()
		{
		}
		void operations();
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
		LinkedList<t> operator + (const LinkedList<t> l2);
};

template <class t>
void LinkedList<t> :: traverse()
{
	cout<<"\nList: \n";
	node * temp=new node;
	temp=first;
	while(temp!=NULL)
	{
		cout<<temp->info;
		if(temp->next!=NULL)
			cout<<" -> ";
		temp=temp->next;
	}
}

template <class t>
int LinkedList<t> :: isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}

template <class t>
void LinkedList<t> :: insert_at_beg()
{
	node * input=new node;
	cout<<"\nEnter data: ";
	cin>>input->info;
	input->next=NULL;
	if(first==NULL)
	{
		first = last = input;
	}
	else
	{
		input->next=first;
		first=input;
	}
	traverse();
}

template <class t>
void LinkedList<t> :: insert_at_end()
{
	node * input=new node;
	cout<<"\nEnter data: ";
	cin>>input->info;
	input->next=NULL;
	if(first == NULL)
	{
		first = last = input;
	}
	else
	{
		last->next=input;
		last=input;
	}
	traverse();
}

template <class t>
void LinkedList<t> :: insert_at_loc()
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

template <class t>
void LinkedList<t> :: del_at_beg()
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
		cout<<"\nDeleted element: ";
		cout<<first->info;
		first=first->next;
		traverse();
	}
}

template <class t>
void LinkedList<t> :: del_at_end()
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
		while(temp->next!=last)
		{
			temp=temp->next;
		}
		cout<<"\nDeleted element: ";
		cout<<last->info;
		temp->next=NULL;
		delete last;
		last=temp;
		traverse();
	}
}

template <class t>
void LinkedList<t> :: del_at_loc()
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

template <class t>
void LinkedList<t> :: reverse()
{
	node *tempf=new node;
	node *templ=new node;
	tempf=first;
	templ=last;
	while(tempf->next!=NULL)
	{
		while(tempf->next!=templ)
			tempf=tempf->next;
		templ->next=tempf;
		tempf->next=NULL;
		templ=tempf;
		tempf=first;
	}
	node *ptr=new node;
	ptr=first;
	first=last;
	last=ptr;
	cout<<"\nReversed list: ";
	traverse();
}

template <class t>
void LinkedList<t> :: search()
{
	int num;
	cout<<"\nEnter number to be serched: ";
	cin>>num;
	node * temp=new node;
	temp=first;
	int flag=0;
	while(temp->next!=NULL)
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

template <class t>
int LinkedList<t> :: count()
{
	node * temp=new node;
	temp=first;
	int n=1;
	while(temp->next!=NULL)
	{
		n++;
		temp=temp->next;
	}
	return n;
}

template <class t>
LinkedList<t> LinkedList<t>::operator + (const LinkedList<t> l2)
{
	last->next = l2.first;
	node *temp = first;
	return *this;
}

template <class t>
void LinkedList<t>::operations()
{
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
		cout<<"\n11. Concatenate";
		cout<<"\n12. Exit";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ insert_at_beg(); break; }
			case 2:{ insert_at_end(); break; }
			case 3:{ insert_at_loc(); break; }
			case 4:{ del_at_beg(); break; }
			case 5:{ del_at_end(); break; }
			case 6:{ del_at_loc(); break; }
			case 7:{ search(); break; }
			case 8:{ if(isempty()==0)
						cout<<"\nEmpty list";
					else
						cout<<"Number of elements: "<<count();
					break;
					}
			case 9:{ traverse(); break; }
			case 10:{reverse(); break; }
			case 11:{				
						LinkedList<int> l2, l3;
						cout<<"\nCreate the second linked list : ";
						l2.operations();
						l3=(*this) + l2;
						l3.traverse();
						break;
					}
			case 12:{ break; }
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=12);	
}

int main()
{
	LinkedList<int> l1;
	l1.operations();
	return 0;
}
