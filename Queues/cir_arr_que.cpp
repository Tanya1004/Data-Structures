#include<iostream> 
using namespace std; 
int size;  
class Queue 
{ 
    int arr[20];
    int rear, front; 
    public:
    	Queue() 
    	{ 
    	   front = rear = -1; 
    	} 
  
	    void enQueue(int value); 
    	int deQueue(); 
   		void displayQueue();
		void clear();
		int firstel();
		int isfull();
		int isempty();
}; 

int Queue :: isfull()
{
	if ((front == 0 && rear == size-1) || front==rear+1) 
        return 1; 
    else
    	return 0;
}

int Queue :: isempty()
{
	if (front == -1) 
    	return 1;
	else
		return 0; 
}
  
void Queue::enQueue(int value) 
{ 
    if (front == -1) 
    { 
        front = rear = 0; 
        arr[rear] = value; 
    } 
    else if (rear == size-1 && front != 0) 
    { 
        rear = 0; 
        arr[rear] = value; 
    } 
    else
    { 
        rear++; 
        arr[rear] = value; 
    } 
} 
   
int Queue::deQueue() 
{ 
   	int data = arr[front]; 
   	arr[front] = -1; 
	if (front == rear) 
   	{
	   	front = -1; 
       	rear = -1; 
    } 
   	else if (front == size-1) 
       	front = 0; 
    else
       	front++; 
    return data; 
} 

void Queue::displayQueue() 
{ 
    if (isempty()==1) 
    { 
        cout<<"\nQueue is Empty"; 
    } 
    cout<<"\nElements in Circular Queue are: \n"; 
    if (rear >= front) 
    { 
        for (int i = front; i <= rear; i++) 
            cout<<arr[i]<<"->";
    } 
    else
    { 
        for (int i = front; i < size; i++) 
            cout<<arr[i]<<"->";
  
        for (int i = 0; i <= rear; i++) 
            cout<<arr[i]<<"->"; 
    } 
} 
  
int Queue::firstel()
{
	return arr[front];
}
void Queue::clear()
{
	for(int i=front; i<=rear; i++)
		cout<<"\nDeleted element: "<<deQueue();
}

int main() 
{ 
    Queue obj;
    int choice;
	cout<<"\nEnter size of array(less than 20): ";
	cin>>size; 
  	do
  	{
  		cout<<"\n\nMENU: \n";
  		cout<<"\n1. Insert an element";
  		cout<<"\n2. Delete an element";
  		cout<<"\n3. First element";
  		cout<<"\n4. Clear";
  		cout<<"\n5. Display";
  		cout<<"\n6. Exit";
  		cout<<"\nEnter your choice: ";
  		cin>>choice;
  		switch(choice)
  		{
  			case 1:{	if(obj.isempty()==1)
			  				cout<<"\nQueue is full";
			  			else
			  			{
						 	int num;
  							cout<<"\nEnter data: ";
  							cin>>num;
  							obj.enQueue(num);
  							obj.displayQueue();
  						}
						break;
			  		}
			case 2:{	int x;
						if(obj.isempty()==1)
							cout<<"\nEmpty Queue";
						else
						{
							x=obj.deQueue();
							cout<<"\nDeleted element: "<<x;
						}
						break;
					}
			case 3:{	int ele;
						ele=obj.firstel();
						cout<<"\nFirst element: "<<ele;
						break;
					}
			case 4:{	obj.clear();
						break;
					}
			case 5:{	obj.displayQueue();
						break;
					}
			case 6:{	exit(0);	}
			default:{	cout<<"\nWrong Choice";
						break;
					} 
		  }
	  }while(choice!=6);
    return 0; 
} 
