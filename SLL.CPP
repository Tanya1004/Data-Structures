#include<iostream.h>
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
		void create();
		void traverse();
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
void main()
{
	clrscr();
	LinkedList l1;
	l1.create();
	l1.traverse();
	getch();
}