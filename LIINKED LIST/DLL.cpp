
#include<iostream.h>
#include<process.h>
#include<conio.h>
class LinkedList
{
	struct node
	{
		int data;
		node *prev, *next;
	}*first;
	public:
		LinkedList()
		{
			first=NULL;
		}
		int isempty();
		void create();
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
int LinkedList :: isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}
void LinkedList :: create()
{
	clrscr();
	char choice;
	do
	{
		node *input=new node;
		cout<<"\nEnter data: ";
		cin>>input->data;
		input->prev=NULL;
		input->prev=NULL;
		if(first==NULL)
		{
			first=input;
			first->next=first;
			first->prev=first;
		}
		else
		{
			node *temp=new node;
			temp=first;
			while(temp->next!=first)
				temp=temp->next;
			temp->next=input;
			input->prev=temp;
			input->next=first;
			first->prev=input;
		}
		cout<<"\nDo you want to continue(y/n): ";
		cin>>choice;
	}while(choice=='y');
	traverse();
}
void LinkedList :: insert_at_begin()
{
	clrscr();
	node * input=new node;
	input->prev=NULL;
	input->next=NULL;
	cout<<"\nEnter data: ";
	cin>>input->data;
	if(first==NULL)
	{
		first=input;
		first->next=first;
		first->prev=first;
	}
	else
	{
		node *temp=new node;
		temp=first;
		input->next=first;
		first->prev=input;
		while(temp->next!=first)
			temp=temp->next;
		temp->next=input;
		input->prev=temp;
		first=input;
	}
	traverse();
}
void LinkedList :: insert_at_end()
{
	clrscr();
	node *input=new node;
	input->prev=NULL;
	input->next=NULL;
	cout<<"\nEnter data: ";
	cin>>input->data;
	node *temp=new node;
	temp=first;
	while(temp->next!=first)
		temp=temp->next;
	temp->next=input;
	input->prev=temp;
	first->prev=input;
	input->next=first;
	traverse();
}
void LinkedList :: insert_at_loc()
{
	clrscr();
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
void LinkedList :: traverse()
{
	node *temp=new node;
	temp=first;
	cout<<"\nList: ";
	while(temp->next!=first)
	{
		cout<<temp->data;

		if(temp->next!=NULL)
			cout<<"->";
		temp=temp->next;
	}
	if(temp->next==first)
		cout<<temp->data;
}
void LinkedList :: del_at_begin()
{
	clrscr();
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
		node *temp=new node;
		temp=first->next;
		first->next=NULL;
		temp->prev=first->prev;
		(first->prev)->next=temp;
		first=temp;
		traverse();
	}
}
void LinkedList :: del_at_end()
{
	clrscr();
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted element: "<<first->data;
		first=NULL;
	}
	else
	{
		node *templ= new node;
		cout<<"\nDeleted element: ";
		templ = first->prev;
		cout<<templ->data;
		templ->prev->next = first;
		first->prev = templ->prev;
		traverse();
	}
}
void LinkedList :: del_at_loc()
{
	clrscr();
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

int LinkedList :: count()
{
	clrscr();
	node *temp=new node;
	temp=first;
	int count=1;
	while(temp->next!=first)
	{
		count++;
		temp=temp->next;
	}
	return count;
}
void LinkedList :: search()
{
	clrscr();
	int num;
	node *temp=new node;
	temp=first;
	cout<<"\nEnter element to be searched: ";
	cin>>num;
	int flag=0;
	while(temp->next!=first)
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

void main()
{
	clrscr();
	LinkedList l1;
	int choice;
	do
	{
		cout<<"\n\nMENU: ";
		cout<<"\n1. Create list";
		cout<<"\n2. Insert at beginning";
		cout<<"\n3. Insert at end";
		cout<<"\n4. Insert at location";
		cout<<"\n5. Delete at beginning";
		cout<<"\n6. Delete at end";
		cout<<"\n7. Delete at location";
		cout<<"\n8. Search";
		cout<<"\n9. Count";
		cout<<"\n10. Display";
		cout<<"\n11. Exit";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ l1.create(); break; }
			case 2:{ l1.insert_at_begin(); break; }
			case 3:{ l1.insert_at_end(); break; }
			case 4:{ l1.insert_at_loc(); break; }
			case 5:{ l1.del_at_begin(); break; }
			case 6:{ l1.del_at_end(); break; }
			case 7:{ l1.del_at_loc(); break; }
			case 8:{ l1.search(); break; }
			case 9:{ if(l1.isempty()==0)
					cout<<"\nEmpty list";
				else
					cout<<"Number of elements: "<<l1.count();
				break;
				}
			case 10:{ l1.traverse(); break; }
			case 11:{ exit(0); }
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=11);
	getch();
}
