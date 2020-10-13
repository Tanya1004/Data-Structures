#include<iostream>
using namespace std;

class Bnode
{
	public:
		Bnode *left, *right;
		int data;
		Bnode()
		{
			left=right=NULL;
		}
		Bnode(int x)
		{
			data=x;
			left=right=NULL;
		}
};

class Queue
{
	struct Node
	{
		Bnode *data;
		Node *next;
	}*front, *rear;
	public:
		Queue()
		{
			front=NULL;
			rear=NULL;
		}
		int isempty()
		{
			if(front==NULL)
				return 1;
			else
				return 0;
		}
		void enqueue(Bnode *num)
		{
			Node *n=new Node;
			n->data=num;
			if(rear==NULL)
			{
				rear=n;
		
				if(front==NULL)
					front=n;
			}
			else
			{
				Node *temp=front;
				while(temp!=rear)
				{
					temp=temp->next;
				}
				temp->next=n;
				rear=n;
			}
			
		}
		Bnode* dequeue()
		{
			Node *p=front;
			Bnode *x=new Bnode;
			if(front==rear)
			{
				front=rear=NULL;
				x=p->data;
				delete p;
				return x;
			}
			else
			{
				front=front->next;
				Bnode *r=new Bnode;
				r=p->data;
				delete(p);
				return r;
			}
		}
};

class Stack
{
	struct Node
	{
		Bnode* data;
		Node *next;
	}*top;
	public:
		Stack()
		{
			top=NULL;
		}
		int isempty();
		void push(Bnode*);
		Bnode* pop();
		~Stack()
		{
			delete top;
		}
		Bnode* gettop()
		{
			return top->data;
		}
};

int Stack :: isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}

void Stack :: push(Bnode* num)
{
	Node *temp = new Node;
	temp->data=num;
	temp->next=top;
	top=temp;
}

Bnode* Stack :: pop()
{
	Node *ptr=new Node;
	ptr=top;
	Bnode* x;
	x=ptr->data;
	top=top->next;
	delete ptr;
	return x;
}

class Bst
{
	private:
		Bnode *root;
	public:
		Bst();
		void tasks();
		void insert_node();
		int search_node(int num);
		void rec_inorder(Bnode *p);
		void rec_preorder(Bnode *p);
		void rec_postorder(Bnode *p);
		void iter_inorder();
		void iter_preorder();
		void iter_postorder();
		void bfs();
		void mirror();
		int count_leaf(Bnode *p);
		int count_nodes(Bnode *p);
		int count_nonleaf(Bnode *p);
		int height(Bnode *p);
		void delmerg(int);
		void delcop(int);
};

Bst :: Bst()
{
	root=NULL;
}

void Bst :: insert_node()
{
	int num;
	cout<<"\nEnter element(0 to stop): ";
		cin>>num;
	do
	{
		Bnode *p=new Bnode;
		p=root;
		Bnode *parent=new Bnode;
		parent=NULL;
		Bnode *temp=new Bnode;
		temp->data=num;
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			while(p!=NULL)
			{
				parent=p;
				if(num<p->data)
					p=p->left;
				else
					p=p->right;	
			}
			if(num<parent->data)
				parent->left=temp;
			else
				parent->right=temp;
		}
		cout<<"\nEnter element(0 to stop): ";
		cin>>num;
	}while(num!=0);
}

void Bst :: delcop(int num)
{
	Bnode *p=root, *parent=root;
	
	while(p!=NULL)
	{
		if(p->data==num)
			break;
		parent=p;
		if(num<p->data)
			p=p->left;
		else
			p=p->right;
	}
	
	if(p->left==NULL&&p->right==NULL)			//no child
	{
		if(p==parent->left)
			parent->left=NULL;
		else
			parent->right=NULL;
			
		delete(p);
	}
	
	else if(p->left==NULL||p->right==NULL)		//one child
	{
		if(p==parent->right)
		{
			if(p->left!=NULL)
				parent->right=p->left;
			else
				parent->right=p->right;
		}
		else if(p==parent->left)
		{
			if(p->left!=NULL)
				parent->left=p->left;
			else
				parent->left=p->right;
		}
		
		delete(p);
	}
	
	else
	{
		Bnode *tmp=p->left;
		parent=p;
		
		while(tmp->right!=NULL)
		{
			parent=tmp;
			tmp=tmp->right;
		}
		
		p->data=tmp->data;
		parent->right=tmp->left;
		
		delete(tmp);
	}
}

int Bst :: search_node(int num)
{
	Bnode *p=new Bnode;
	p=root;
	while(p!=NULL)
	{
		if(num==p->data)
			return 1;
		else if(num<p->data)
			p=p->left;
		else
			p=p->right;
	}
	return 0;
}

void Bst :: rec_inorder(Bnode *p)
{
	if(p!=NULL)
	{
		rec_inorder(p->left);
		cout<<p->data<<"  ";
		rec_inorder(p->right);
	}
}

void Bst :: rec_preorder(Bnode *p)
{
	if(p!=NULL)
	{
		cout<<p->data<<"  ";
		rec_preorder(p->left);
		rec_preorder(p->right);
	}
}

void Bst :: rec_postorder(Bnode *p)
{
	if(p!=NULL)
	{
		rec_postorder(p->left);
		rec_postorder(p->right);
		cout<<p->data<<"  ";
	}
}

void Bst :: iter_inorder()
{
	Stack s;
	Bnode *p=new Bnode;
	p=root;
	while(p!=NULL||s.isempty()!=1)
	{
		if(p!=NULL)
		{
			s.push(p);
			p=p->left;
		}
		else
		{
			p=s.gettop();
			cout<<(s.pop())->data<<"  ";
			p=p->right;
		}
	}
}

void Bst :: iter_preorder()
{
	Stack s;
	Bnode *p=new Bnode;
	p=root;
	if(p!=NULL)
	{
		s.push(p);
		while(!s.isempty())
		{
			p=s.pop();
			cout<<p->data<<"   ";
			if(p->right!=NULL)
				s.push(p->right);
				
			if(p->left!=NULL)
				s.push(p->left);
		}
	}
}

void Bst :: iter_postorder()
{
	Stack s;
	Bnode *p=root, *q=root;
	int x=0;
	while(p!=NULL)
	{
		for(; p->left!=NULL; p=p->left)
			s.push(p);
			
		while(p!=NULL&&(p->right==NULL||p->right==q))
		{
			cout<<p->data<<"   ";
			q=p;
			if(s.isempty())
				return;
			p=s.pop();
		}
		
		s.push(p);
		p=p->right;
	}
}

void Bst :: bfs()
{
	Queue q;
	Bnode *p=root;
	int fl=0;
	if(p!=NULL)
	{
		q.enqueue(p);
		while(q.isempty()!=1)
		{
			p=q.dequeue();
			cout<<p->data<<"   ";
			if(p->left!=NULL)
				q.enqueue(p->left);
			if(p->right!=NULL)
				q.enqueue(p->right);
		}
	}
}

void Bst :: mirror()
{
	Queue q;
	Bnode *p=root;
	int fl=0;
	if(p!=NULL)
	{
		q.enqueue(p);
		while(q.isempty()!=1)
		{
			p=q.dequeue();
			cout<<p->data<<"   ";
			if(p->right!=NULL)
				q.enqueue(p->right);
			if(p->left!=NULL)
				q.enqueue(p->left);
		}
	}
}

int Bst :: count_nonleaf(Bnode *p)
{
	if(p==NULL||(p->left==NULL&&p->right==NULL))
		return 0;
	else
		return (1+count_nonleaf(p->left)+count_nonleaf(p->right));
}

int Bst :: count_leaf(Bnode *p)
{
	if(p==NULL)
		return 0;
	else if(p->left==NULL&&p->right==NULL)
		return 1;
	else
		return (count_leaf(p->left)+count_leaf(p->right));
}

int Bst :: count_nodes(Bnode *p)
{
	if(p==NULL)
		return 0;
	else
		return (1+ count_nodes(p->left)+count_nodes(p->right));
}

int Bst :: height(Bnode *p)
{
	if(p==NULL)
		return 0;
	else
		return(1+ max(height(p->left), height(p->right)));
}

void Bst :: delmerg(int num)
{
	Bnode *p=root, *parent=root;
	
	while(p!=NULL)
	{
		if(p->data==num)
			break;
		parent=p;
		if(num<p->data)
			p=p->left;
		else
			p=p->right;
	}
	
	if(p->left==NULL&&p->right==NULL)			//no child
	{
		if(p==parent->left)
			parent->left=NULL;
		else
			parent->right=NULL;
			
		delete(p);
	}
	
	else if(p->left==NULL||p->right==NULL)		//one child
	{
		if(p==parent->right)
		{
			if(p->left!=NULL)
				parent->right=p->left;
			else
				parent->right=p->right;
		}
		else if(p==parent->left)
		{
			if(p->left!=NULL)
				parent->left=p->left;
			else
				parent->left=p->right;
		}
		
		delete(p);
	}
	
	else										//two children
	{
		Bnode *tmp = p->left;
		while(tmp->right!=NULL)					//finding rightmost elem (predecessor of node to be deleted)
			tmp=tmp->right;
			
		tmp->right=p->right;
		p->right=NULL;
		//tmp=p;
		
		if(p==parent)
			root=p->left;
		else if(p==parent->right)
			parent->right=p->left;
		else
			parent->left=p->left;
			
		delete(p);
		Bnode *p=tmp;
	}
}

void Bst :: tasks()
{
	int ch;
	
	do
	{
		cout<<"\n\n\t*****BINARY SEARCH TREES*****";
		cout<<"\n1. Insert node";
		cout<<"\n2. Show inorder traversal (recursive)";
		cout<<"\n3. Show inorder traversal (iterative)";
		cout<<"\n4. Show preorder traversal (recursive)";
		cout<<"\n5. Show preorder traversal (iterative)";
		cout<<"\n6. Show postorder traversal (recursive)";
		cout<<"\n7. Show postorder traversal (iterative)";
		cout<<"\n8. Search element";
		cout<<"\n9. Delete a node (by merging)";
		cout<<"\n10. Delete a node (by copying)";
		cout<<"\n11. Count number of leaf nodes";
		cout<<"\n12. Count total number of nodes";
		cout<<"\n13. Count no. of non-leaf nodes";
		cout<<"\n14. Calculate height";
		cout<<"\n15. Breadth First Traversal";
		cout<<"\n16. Create a mirror image";
		cout<<"\n17. Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>ch;
		
		switch(ch)
		{
			case 1: {
						//insert
					    insert_node();
						break;
					}
			case 2: {
						//recursive inorder
						if(root!=NULL)
							rec_inorder(root);
						else
							cout<<"\nEmpty tree!"<<endl;
						break;
					}
			case 3:{
						//iterative inorder
						if(root!=NULL)
							iter_inorder();
						else
							cout<<"\nEmpty tree!"<<endl;
						break;
					}
			case 4: {
						//recursive preorder
						if(root!=NULL)
							rec_preorder(root);
						else
							cout<<"\nEmpty tree!"<<endl;
						break;
					}
			case 5: {
						//iterative preorder
						if(root!=NULL)
							iter_preorder();
						else
							cout<<"\nEmpty tree!"<<endl;
						break;
					}
			case 6: {
						//recursive postorder
						if(root!=NULL)
							rec_postorder(root);
						else
							cout<<"\nEmpty Tree!"<<endl;
						break;
					}
			case 7: {
						//iterative postorder
						if(root!=NULL)
							iter_postorder();
						else
							cout<<"\nEmpty tree!"<<endl;
						break;
					}
			case 8: {
						//search
						int itm;
						cout<<"\nEnter element to be searched : ";
						cin>>itm;
						if(root==NULL)
							cout<<"\nEmpty tree!";
						else
						{
							if(search_node(itm))
								cout<<"\nElement found!";
							else
								cout<<"\nElement not found!";
						}
						break;
					}
			case 9 :{	//deletion by merging
						int ele;
						cout<<"\nEnter element to be deleted: ";
						cin>>ele;
						if(root!=NULL && search_node(ele))
							delmerg(ele);
						else
							cout<<"\nNo such element";			
						break;
					}
			case 10: {	//deletion by copying
						int ele;
						cout<<"\nEnter element to be deleted: ";
						cin>>ele;
						if(root!=NULL && search_node(ele))
							delcop(ele);
						else
							cout<<"\nNo such element";			
						
						break;
					}
			case 11:{
						//leaf nodes
						if(root==NULL)
							cout<<"\nEmpty tree!"<<endl;
						else
							cout<<"\nTotal number of leaf nodes = "<<count_leaf(root)<<endl;
						
						break;
					}
			case 12:{
						//total nodes
						if(root==NULL)
							cout<<"\nEmpty tree!"<<endl;
						else
							cout<<"\nTotal number of nodes = "<<count_nodes(root)<<endl;
						
						break;
					}
			case 13:{
						//non-leaf nodes
						if(root==NULL)
							cout<<"\nEmpty tree!"<<endl;
						else
							cout<<"\nNumber of non leaf nodes = "<<count_nonleaf(root);
						break;
					}
			case 14:{
						//height
						if(root==NULL)
							cout<<"\nEmpty tree! Height = 0"<<endl;
						else
							cout<<"\nHeight = "<<height(root)<<endl;
						
						break;
					}
			case 15:{
						//bfs traversal
						if(root==NULL)
							cout<<"\nEmpty tree!"<<endl;
						else
						{
							cout<<"\nBreadth First Traversal : ";
							bfs();
						}
						
						break;
					}
			case 16: {
						//mirror image
						if(root==NULL)
							cout<<"\nEmpty tree"<<endl;
						else
						{
							cout<<"\nMirror: "<<endl;
							mirror();
						}
						
						break;
					}
			case 17: break;			
					
		   default : cout<<"\nWrong chocice";
		}
	}while(ch!=17);
}

int main()
{
	Bst b;
	b.tasks();
	return 0;
}
