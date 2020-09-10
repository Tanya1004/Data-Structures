#include<iostream>
#include<math.h>
using namespace std;
class Number
{
	struct Node
	{
		int data;
		Node *next;
	}*top;
	public:
		Number()
		{
			top=NULL;
		}
		void create(long);
		void push(int);
		int pop();
		void add(Number, Number);
		int digits(long);
		void display();
		int isempty();
		~Number()
		{
			delete top;
		}
};
int Number :: isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
int Number :: digits(long num)
{
	int count=0;
	while(num!=0)
	{
		num=num/10;
		++count;
	}
	return count;
}
void Number :: push(int n)
{
	Node *temp = new Node;
	temp->data=n;
	temp->next=top;
	top=temp;
}
int Number :: pop()
{
	if(isempty()==0)
	{
		Node *ptr=new Node;
		ptr=top;
		int x;
		x=ptr->data;
		top=top->next;
		delete ptr;
		return x;
	}
	else
		return 0;
}
void Number :: create(long num)
{
	int dig, n1;
	dig=digits(num);
	
	do
	{
		n1=num/pow(10,dig-1);
		push(n1);
		num=num-(n1*pow(10, dig-1));
		dig--;
	}while(dig!=0);
	display();
}
void Number :: add(Number n1, Number n2)
{
	int carry=0;
	while((n1.isempty()!=1)||(n2.isempty()!=1))
	{
		int x;
		x=n1.pop()+n2.pop()+carry;
		if(x>=10)
		{
			carry=x/10;
			x=x%10;
			push(x);
		}
		else
		{
			push(x);
			carry=0;
		}
	}
	display();
}
void Number :: display()
{
	if(isempty()==1)
		cout<<"\nEmpty stack";
	else
	{
		Node *temp=new Node;
		temp=top;
		cout<<"\nStack: \n";
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}

}
int main()
{
	Number ob1, ob2;
	long first, second;
	cout<<"\nEnter first number: ";
	cin>>first;
	ob1.create(first);
	cout<<"\nEnter second number: ";
	cin>>second;
	ob2.create(second);
	Number n3;
	cout<<"\nFinal Number: ";
	n3.add(ob1, ob2);
}
