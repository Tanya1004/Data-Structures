#include<iostream>
using namespace std;

int max(int a, int b)
{
	return (a>b?a:b);
}


class Node
{
	public:
		Node *left, *right, *parent;
		int data, height, bf;
		Node()
		{
			parent=left=right=NULL;
		}
		Node(int x)
		{
			data=x;
			left=right=NULL;
		}
};

class Tree
{
	private:
		Node *root;
	public:
		Tree();
		void tasks();
		Node* insert_node(Node*,int);
		void display(Node*);
		int height(Node *p);
		int balancefactor(Node *p);
		Node* deleted(Node*, int);
		Node* balance(Node *p);
		Node* rr_rotation(Node*);
		Node* rl_rotation(Node*);
		Node* lr_rotation(Node*);
		Node* ll_rotation(Node*);
};

Tree :: Tree()
{
	root=NULL;
}

void Tree :: tasks()
{
	int choice;
	do
	{
		cout<<"\nMENU: ";
		cout<<"\n1. Insert";
		cout<<"\n2. Display";
		cout<<"\n3. Delete";
		cout<<"\n4. Exit";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: {	int num;
						cout<<"\nEnter value: ";
						cin>>num;
						root=insert_node(root, num);
						cout<<"\nInorder traversal: ";
						display(root);
						break;
					}
			case 2:{	cout<<"\nInorder Traversal: ";
						display(root);
						break;
					}
			case 3: {	int num;
						cout<<"\nEnter value to be deleted: ";
						cin>>num;
						root=deleted(root, num);
						cout<<"\nInorder traversal: ";
						display(root);
						break;
					}
			case 4: {	exit(0);	}
			default:	cout<<"\nWrong choice";
		}
	}while(choice!=4);
}

Node *Tree::insert_node(Node *root, int value)
{
	if (root == NULL)
	{
		root = new Node;
		root->data = value;
		root->left = NULL;
		root->right = NULL;
		root->parent=NULL;
		return root;
	}
	else if (value < root->data)
	{
		root->left = insert_node(root->left, value);
		root = balance (root);
	}
	else if (value >= root->data)
	{
		root->right = insert_node(root->right, value);
		root = balance (root);
	}
	return root;
}

Node* Tree :: balance(Node *p)
{
	p->bf=balancefactor(p);
	p->height=height(p);
	if(p->bf>1)
	{
		if((p->left)->bf>0)
			p=ll_rotation(p);
		else
			p=lr_rotation(p);
	}
	else if(p->bf<-1)
	{
		if((p->right)->bf>0)
			p=rl_rotation(p);
		else
			p=rr_rotation(p);
	}
	return p;
}

int Tree :: height(Node *p)
{
	if(p==NULL)
		return 0;
	else
		return(1+ max(height(p->left), height(p->right)));
}

int Tree :: balancefactor(Node *p)
{
	int height_left, height_right;
	if(p->left==NULL)
		height_left=0;
	else
		height_left=height(p->left);
	if(p->right==NULL)
		height_right=0;
	else
		height_right=height(p->right);
	
	return height_left-height_right;
}

Node *Tree :: rr_rotation(Node *ptr)
{
	Node *temp;
	temp = ptr->right;
	ptr->right = temp->left;
	temp->left = ptr;
	return temp;
}

Node *Tree :: ll_rotation(Node *ptr)
{
	Node *temp;
	temp = ptr->left;
	ptr->left = temp->right;
	temp->right = ptr;
	return temp;
}

Node *Tree :: rl_rotation(Node *ptr)
{
	Node *temp;
	temp = ptr->right;
	ptr->right = ll_rotation (temp);
	return rr_rotation (ptr);
}

Node *Tree :: lr_rotation(Node *ptr)
{
	Node *temp;
	temp = ptr->left;
	ptr->left = rr_rotation (temp);
	return ll_rotation (ptr);
}

void Tree :: display(Node *p)
{
	if(p!=NULL)
	{
		display(p->left);
		cout<<p->data<<"  ";
		display(p->right);
	}
}

Node *Tree :: deleted(Node * root, int value)
{
	Node *p;
	if(root==NULL)
	{
		return NULL;
	}
	else
	if(value>root->data)
	{
		root->right=deleted(root->right,value);
		root=balance(root);
	}
	else if(value < root->data)
	{
		root->left=deleted(root->left,value);
		root=balance(root);
	}
	else
	{
		if(root->right!=NULL)
		{
			p=root->right;
			while(p->left!= NULL)
				p=p->left;
			root->data=p->data;
			root->right=deleted(root->right,p->data);
		}
	else
		return(root->left);
	}
	return root;
}

int main()
{
	Tree t1;
	t1.tasks();
	return 0;
}
