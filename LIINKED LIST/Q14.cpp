#include<iostream>
using namespace std;

class List
{
	struct node
	{
		int data;
		node *next;
	}*first, *last;
	public:
		List()
		{
			first=last=NULL;
		}
		int isempty();
		int count();
		void operations();
		void insert_sorted(int num);
		void del_at_beg();
		void del_at_end();
		void del_at_loc();
		void merge(List l2);
		void traverse();
		~List()
		{		}
};

int List::isempty()
{
	if(first==NULL)
		return 0;
	else
		return 1;
}

int List::count()
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

void List :: operations()
{
	int choice;
	char ch;
	do
	{
		cout<<"\nMENU: ";
		cout<<"\n1. Insert";
		cout<<"\n2. Delete at beginning";
		cout<<"\n3. Delete at end";
		cout<<"\n4. Delete at location";
		cout<<"\n5. Merging";
		cout<<"\n6. Display";
		cout<<"\n7. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: { 	int dat;
						cout<<"\nEnter data: ";
						cin>>dat;
						insert_sorted(dat); 
						traverse();
						break; 
					}
			case 2: { del_at_beg(); break; }
			case 3: { del_at_end();	break;	}
			case 4: { del_at_loc(); break; }
			case 5: { 	List l2;
						cout<<"\nNOW ENTER FOR SECOND LIST";
						l2.operations();
						merge(l2);
						break; 
					}
			case 6: { traverse(); break; }
			case 7: { break; }
			default: { cout<<"\nIncorrect choice"; break; }
		}
	}while(choice!=7);	
}
void List :: insert_sorted(int num)
{
	node *input=new node;
	input->data=num;
	input->next=NULL;
	if(first==NULL)
	{
		input->next=first;
        first=last=input;
	}
	else if(first->data<=input->data)
    {
        input->next=first;
        first=input;
    }
    else
   	{
    	node *temp=new node;
		temp=first;
        while(temp->next!=NULL && (temp->next->data>input->data))
        {
        	temp=temp->next;
        }
        if(temp==last)
        {
        	temp->next=input;
			last = input;	
		}
		else
		{
			input->next=temp->next;
        	temp->next=input;
    	}
    }
    //traverse();
}
void List :: del_at_beg()
{
	if(isempty()==0)
		cout<<"\n No elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted Element : "<<first->data;
		first=NULL;
	}
	else
	{
		cout<<"\nDeleted element: ";
		cout<<first->data;
		first=first->next;
		traverse();
	}
}

void List :: del_at_end()
{
	if(isempty()==0)
		cout<<"\nNo elements in list";
	else if(count()==1)
	{
		cout<<"\nDeleted Element : "<<first->data;
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
		cout<<last->data;
		temp->next=NULL;
		delete last;
		last=temp;
		traverse();
	}
}
void List :: del_at_loc()
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
			cout<<"\nDeleted element: "<<temp1->data;
			temp->next=temp1->next;
			delete temp1;
			traverse();
		}
	}
}
void List :: traverse()
{
	cout<<"\nList: \n";
	node * temp=new node;
	temp=first;
	while(temp!=NULL)
	{
		cout<<temp->data;
		if(temp->next!=NULL)
			cout<<" -> ";
		temp=temp->next;
	}
}
void List :: merge(List l3)
{
	node *t1 = new node;
	t1=first;
	node *t2 = new node;
	t2=l3.first;
	List result;
	
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->data==t2->data)
		{
			result.insert_sorted(t1->data);
			t1=t1->next;
			t2=t2->next;
		}
		else if(t1->data > t2->data)
		{
			result.insert_sorted(t1->data);
			t1=t1->next;
		}
		else if(t2->data > t1->data)
		{
			result.insert_sorted(t2->data);
			t2=t2->next;
		}
	}
	while(t1!=NULL)
	{
		result.insert_sorted(t1->data);
		t1=t1->next;
	}
	while(t2!=NULL)
	{
		result.insert_sorted(t2->data);
		t2=t2->next;
	}
	
	cout<<"\nMerged List: ";
	result.traverse();
}
int main()
{
	List l1;
	l1.operations();
	return 0;
}
