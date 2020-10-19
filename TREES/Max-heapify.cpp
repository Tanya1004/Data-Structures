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
	cout<<"\nEnter array elements: ";
	for(int i=1; i<=size; i++)
	{
		cin>>arr[i];
	}
	int pos;
	cout<<"\nEnter position for max-heapify: ";
	cin>>pos;
	max_heapify(arr, pos);
	
	cout<<"\nArray after max-heapify: ";
	for(int i=1; i<=size; i++)
		cout<<"  "<<arr[i];
	return 0;
}
