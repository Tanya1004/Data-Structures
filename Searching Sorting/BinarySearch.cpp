#include<iostream>
using namespace std;

int *arr;
int size;

int binary_search(int elem)
{
    int beg=0, en=size, mid;
    int flag=-1;

    while(beg<=en&&flag==-1)
    {
        mid=(beg+en)/2;

        if(arr[mid]==elem)
        {
            flag=mid;
            return flag;
        }
        else if(arr[mid]<elem)
        {
            beg=mid+1;
        }

        else
            en=mid-1;
    }

    return -1;
}

int main()
{
	cout<<"\nEnter number of elements in the list : ";
	cin>>size;
	
	arr = new int[size];
	
	cout<<"\nEnter list of elements in ascending order : ";
	for(int x=0; x<size; ++x)
	{
		cin>>arr[x];
	}
	
	int it;
	cout<<"\nEnter item to be searched : ";
	cin>>it;
	
	int res = binary_search(it);
	if(res==-1)
		cout<<"\nElement not found!";
	else
		cout<<"\nElement found at index : "<<res;
	return 0;
}
