#include<iostream>
using namespace std;

class Diagonal
{
	int *arr;
	int n;
	
	public:
		Diagonal()
		{
			cout<<"\nEnter size of square matrix : ";
			cin>>n;
			
			arr = new int[n];
		}
		
		void input()
		{
			cout<<"\nEnter diagonal elements: ";
			int y;
			for(int i=0, j=0; i<n, j<n; ++i, ++j)
			{
				cin>>y;
				store(y, i, j);
			}	
		}
		
		void store(int val, int p1, int p2)
		{
			if(p1<0 || p2<0 || p1>n-1 || p2>n-1)
			{
				cout<<"\nIndex out of bounds!";
				exit(0);
			}
			else if(p1!=p2 && val!=0)
			{
				cout<<"\nValue must be zero!";
				exit(0);
			}
			else
				arr[p1] = val;
		}
		
		int retrieve(int p1, int p2)
		{
			if(p1<0 || p2<0 || p1>n-1 || p2>n-1)
			{
				cout<<"\nIndex out of bounds!";
				exit(0);
			}
			else if(p1==p2)
				return arr[p1];
			else
				return 0;
		}
		
		void show()
		{
			for(int i=0; i<n; ++i)
			{
				for(int j=0; j<n; ++j)
				{
					cout<<retrieve(i,j)<<"\t";
				}
				cout<<endl;
			}
		}
		
		~Diagonal()
		{
			delete [] arr;
		}
};

int main()
{
	Diagonal d_ob;
	d_ob.input();
	
	cout<<"\nPrinting the 2-D matrix : \n\n";
	d_ob.show();
	return 0;
}
