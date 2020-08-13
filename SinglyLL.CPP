#include<iostream.h>
#include<process.h>
#include<conio.h>
class LinkedList
{
	struct node
	{
		int info;
		node *next;
	}*first, *last;
	public:
		LinkedList()
		{
			first= NULL;
		}
		~LinkedList()
		{}
		void create();
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
void LinkedList :: create()
{
	char ch;
	do
	{
		node * head=new node;
		head->next=NULL;
		cout<<"\nEnter data: ";
		cin>>head->info;
		if(first==NULL)
		{
			first=head;
			first->next=NULL;
			first->info=head->info;
			last=first;
		}
		else
		{
			last->next=head;
			last=head;
		}
		cout<<"\nDo you want to continue(y/n): ";
		cin>>ch;
	}while(ch=='y');
	traverse();
}
void LinkedList :: traverse()
{
	clrscr();
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
int LinkedList :: isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}
void LinkedList :: insert_at_beg()
{
	clrscr();
	node * head=new node;
	cout<<"\nEnter data: ";
	cin>>head->info;
	head->next=NULL;
	head->next=first;
	first=head;
	traverse();
}
void LinkedList :: insert_at_end()
{
	clrscr();
	node * head=new node;
	cout<<"\nEnter data: ";
	cin>>head->info;
	head->next=NULL;
	last->next=head;
	last=head;
	traverse();
}
void LinkedList :: insert_at_loc()
{
	clrscr();
	int loc;
	node * temp=new node;
	node * head=new node;
	head=first;
	cout<<"\nEnter data: ";
	cin>>temp->info;
	temp->next=NULL;
	cout<<"\nEnter location: ";
	cin>>loc;
	int num=1;
	while(num<loc-1)
	{
		head=head->next;
		num++;
	}
	temp->next=head->next;
	head->next=temp;
	traverse();
}
void LinkedList :: del_at_beg()
{
	clrscr();
	if(isempty()==0)
		cout<<"\n No elements in list";
	else
	{
		cout<<"\nDeleted element: ";
		cout<<first->info;
		first=first->next;
	}
	traverse();
}
void LinkedList :: del_at_end()
{
	clrscr();
	if(isempty()==0)
		cout<<"\nNo elements in list";
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
	}
	traverse();
}
void LinkedList :: del_at_loc()
{
	clrscr();
	int loc;
	node * head=new node;
	head=first;
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else
	{
		cout<<"\nEnter location: ";
		cin>>loc;
		if(loc==1)
			del_at_beg();
		else
		{
			if(loc==count())
				del_at_end();
			else
			{
				int num=1;
				while(num<loc-1)
				{
					head=head->next;
					num++;
				}
				node * temp=new node;
				temp=head->next;
				cout<<"\nDeleted element: "<<temp->info;
				head->next=temp->next;
				delete temp;
			}
		}
	}
	traverse();
}
void LinkedList :: reverse()
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

void LinkedList :: search()
{
	clrscr();
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
int LinkedList :: count()
{
	clrscr();
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
		cout<<"\n11. Reverse";
		cout<<"\n12. Exit";
		cout<<"\nChoice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:{ l1.create(); break; }
			case 2:{ l1.insert_at_beg(); break; }
			case 3:{ l1.insert_at_end(); break; }
			case 4:{ l1.insert_at_loc(); break; }
			case 5:{ l1.del_at_beg(); break; }
			case 6:{ l1.del_at_end(); break; }
			case 7:{ l1.del_at_loc(); break; }
			case 8:{ l1.search(); break; }
			case 9:{ cout<<"Number of elements: "<<l1.count(); break; }
			case 10:{ l1.traverse(); break; }
			case 11:{l1.reverse(); break; }
			case 12:{ exit(0); }
			default:{ cout<<"\nWrong choice: "; }
		}
	}while(choice!=12);
	getch();
}
