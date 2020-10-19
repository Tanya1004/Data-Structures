#include<iostream>
using namespace std;
int size;

void max_heapify(int arr[], int pos)
{
	int left, right, largest, temp;
	left=2*pos;
	right=2*pos+1;
	if(left<size && arr[left]>arr[pos])
		largest=left;
	else
		largest=pos;
	if(right<=size && arr[right]>arr[largest])
		largest=right;
	if(largest!=pos)
	{
		temp=arr[pos];
		arr[pos]=arr[largest];
		arr[largest]=temp;
		max_heapify(arr, largest);
	}
}

void build_max_heap(int arr[])
{
	for(int i=size/2; i>=1; i--)
		max_heapify(arr, i);
}

void heap_increase_key(int arr[], int i, int key)
{
	if(key<arr[i])
		cout<<"\nError: New key is smaller than current key";
	else
		arr[i]=key;
		
	int parent;
	parent=i/2;
	
	while(i>1 && arr[parent]<arr[i])
	{
		int temp;
		temp=arr[i];
		arr[i]=arr[parent];
		arr[parent]=temp;
		i=parent;
		parent=i/2;
	}
}

void max_heap_insert(int arr[], int key)
{
	size++;
	arr[size]=-342;
	heap_increase_key(arr, size, key);
}

int heap_maximum(int arr[])
{
	return arr[1];
}

int heap_extract_max(int arr[])
{
	int max;
	if(size<1)
		cout<<"\nHeap underflow";
	else
	{
		max=arr[1];
		arr[1]=arr[size];
		size--;
		max_heapify(arr, 1);
	}
}

void show(int arr[])
{
	cout<<"\n";
	for(int i=1; i<=size; i++)
		cout<<arr[i]<<"  ";
}

int main()
{
	int arr[50];
	do
	{
		cout<<"\nEnter size of array(less than 50): ";
		cin>>size;
		if(size>50 || size<0)
			cout<<"\nEnter again.";
	}while(size>50 || size<0);
	
	cout<<"\nEnter array elements for Priority Queue: ";
	for(int i=1; i<=size; i++)
	{
		cin>>arr[i];
	}	
	
	build_max_heap(arr);
	show(arr);
	
	int choice;
	do
	{
		cout<<"\n\nMENU";
		cout<<"\n1. Heap Increase Key";
		cout<<"\n2. Max Heap Insert";
		cout<<"\n3. Heap Maximum";
		cout<<"\n4. Heap Extract Max";
		cout<<"\n5. Exit";
		cout<<"\nEnter choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1: { 	int key, i;
						cout<<"\nEnter key: ";
						cin>>key;
						cout<<"\nEnter position: ";
						cin>>i;
						heap_increase_key(arr, i, key);
						cout<<"\nHeap after increasing: ";
						show(arr);
						break;
					}
			case 2:{	int key;
						cout<<"\nEnter key: ";
						cin>>key;
						max_heap_insert(arr, key);
						cout<<"\nHeap after max heap insertion: ";
						show(arr);
						break;
					}
			case 3:{	int max;
						cout<<"\nHeap: ";
						show(arr);
						max=heap_maximum(arr);
						cout<<"\nMaximum: "<<max;
						break;
					}
			case 4:{	int max;
						max=heap_extract_max(arr);
						cout<<"\nHeap after extraction: ";
						show(arr);
						break;
					}
			case 5:{ 	break;	}
			default:{ 	cout<<"\nWrong choice";
						break;
					}
		}
	}while(choice!=5);
	return 0;
}
