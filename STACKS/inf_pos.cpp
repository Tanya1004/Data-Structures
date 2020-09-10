#include<iostream>
#include<string.h>
#include<stdio.h>
#include<ctype.h>

using namespace std;

class Stack
{
	char arr[30];
	int top;
	public:
		Stack()
		{
			for(int i=0; i<30;  i++)
				arr[i]=0;
			top=-1;
		}
		int isempty();
		void push(char);
		char pop();
		char topele();	
};

int Stack:: isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;	
}

void Stack :: push(char c)
{
	top++;
	arr[top]=c;
}

char Stack:: pop()
{
	if(isempty()==1)
		cout<<"\nUnderflow";
	else
	{
		char x;
		x=arr[top];
		top--;
		return x;
	}
}

char Stack:: topele()
{
	return arr[top];
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
    }
}

int main()
{
    char inf[80];
    char post[80];
    Stack s;
    int flag=0;

    cout<<"Enter infix expression: ";
    cin>>inf;

    for(int i=0; i<80; ++i)
        post[i]=' ';

    int len=strlen(inf);
    int ctr=0;

    for(int i=0; i<len; ++i)
    {
        if(isalnum(inf[i]))
        {
            post[ctr]=inf[i];
            ctr++;
        }
        else if(inf[i]=='(')
        {
            s.push(inf[i]);
        }
        else if(inf[i]==')')
        {
            char c=s.pop();
            while(c!='(')
            {
                post[ctr]=c;
                ctr++;
                c=s.pop();
            }
        }
        else
        {
            int p1=precedence(inf[i]);
            int p2=0;

            if(!s.isempty())
            {
                do
                {
                    char tmp=s.topele();
                    if(tmp!='(')
                    {
                        p2=precedence(tmp);
                        if(p2>p1)
                        {
                            post[ctr]=s.pop();
                            ctr++;
                        }
                        else
                            break;
                    }
                    else
                        break;
                }while(p2>p1);
                s.push(inf[i]);
            }
            else
                s.push(inf[i]);
        }
    }

    while(!s.isempty())
    {
       post[ctr]=s.pop();
       ctr++;

    }
    post[ctr]='\0';
    cout<<"\nPostfix expression: ";
    puts(post);

    return 0;
}
