#include<iostream>

using namespace std;
const int MAX = 20;

class Expression
{
	struct Node
	{
		char data;
		Node *next;
	}*top;
	public:
		Expression()
		{
			top=NULL;
		}
		void push(char);
		char pop();
		int check_match(char expr[MAX]);
		int isempty();
		~Expression()
		{
			delete top;
		}
};

int Expression :: isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void Expression :: push(char n)
{
	Node *temp = new Node;
	temp->data=n;
	temp->next=top;
	top=temp;
}

char Expression :: pop()
{
	if(isempty()==0)
	{
		Node *ptr=new Node;
		ptr=top;
		char x;
		x=ptr->data;
		top=top->next;
		delete ptr;
		return x;
	}
	else
		return 0;
}

int Expression::check_match(char expr[MAX])
{
	for(int i=0; expr[i]!='\0'; ++i)
	{
		char b = expr[i];
		if(b=='{' || b=='(' || b=='[')
		{
			push(b);
		}
		else if(b=='}')
		{
			char p = pop();
			if(p!='{')
				return -1;
		}
		else if(b==')')
		{
			char p = pop();
			if(p!='(')
				return -1;
		}
		else if(b==']')
		{
			char p = pop();
			if(p!='[')
				return -1;
		}
		else
			continue;
	}
	
	if(isempty())
	{
		return 1;
	}
	else
		return 0;
}

int main()
{
	Expression e;
	char exp[MAX];
	cout<<"\nEnter expression : ";
	gets(exp);
	int status = e.check_match(exp);
	if(status==-1)
		cout<<"\nInvalid Delimiter Encountered!";
	else if(status==0)
		cout<<"\nDelimiter Unmatched!";
	else
		cout<<"\nDelimiter Successfully Matched!";
	return 0;
}
