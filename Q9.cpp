#include<iostream>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
const int MAX = 20;
class Postfix
{
	struct Node
	{
		int data;
		Node *next;
	}*top;
	public:
		Postfix()
		{
			top=NULL;
		}
		void create(char str[]);
		void push(int);
		int pop();
		void display();
		int isempty();
		~Postfix()
		{
			delete top;
		}
};
int Postfix :: isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
void Postfix :: push(int n)
{
	Node *temp = new Node;
	temp->data=n;
	temp->next=top;
	top=temp;
}
int Postfix :: pop()
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
void Postfix :: create(char str[MAX])
{
	char number[5];
	int k=0;
	for(int i=0; str[i]!='\0'; i++)
	{
		if(isdigit(str[i]))
		{
			number[k] = str[i];
			k++;
		}
		else if(str[i]==' ')
		{
			if(k!=0)
			{
				int val = atoi(number);
				push(val);
				k=0;
				for(int x=0; x<5; ++x)
				{
					number[x]='\0';
				}
			}
			else
				continue;
		}
		else
		{
			int right, left;
			right=pop();
			left=pop();
			int result;
			switch(str[i])
			{
				case '+':{result=left+right; break; }
				case '-':{result=left-right; break;	}	
				case '*':{result=left*right; break;	}
				case '/':{result=left/right; break;	}		
				default :{cout<<"\nError"; break;	}
			}
			push(result);
		}
	}
}
void Postfix :: display()
{
	if(isempty()==1)
		cout<<"\nEmpty stack";
	else
	{
		cout<<"\nResult = "<<top->data;
	}

}
int main()
{
	Postfix ob1;
	char str[MAX];
	cout<<"\nEnter expression: ";
	gets(str);
	ob1.create(str);
	ob1.display();
	exit(0);
		
}
