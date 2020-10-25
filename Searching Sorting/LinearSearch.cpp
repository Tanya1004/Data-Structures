#include<iostream>
using namespace std;

int *arr;
int size;

int linear_search(int item)
{
	for(int i=0; i<size; ++i)
	{
		if(arr[i]==item)
			return i;
	}
	return -1;
}

int main()
{
	cout<<"\nEnter number of elements in the list : ";
	cin>>size;
	
	arr = new int[size];
	
	cout<<"\nEnter list of elements : ";
	for(int x=0; x<size; ++x)
	{
		cin>>arr[x];
	}
	
	int it;
	cout<<"\nEnter item to be searched : ";
	cin>>it;
	
	int res = linear_search(it);
	if(res==-1)
		cout<<"\nElement not found!";
	else
		cout<<"\nElement found at index : "<<res;
	return 0;
}
