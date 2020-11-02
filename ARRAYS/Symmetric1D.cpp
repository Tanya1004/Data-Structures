#include<iostream>
using namespace std;

class Symmetric
{
	int *arr;
	int n;
	
	public:
		Symmetric()
		{
			cout<<"\nEnter size of square matrix : ";
			cin>>n;
			
			arr = new int[n*(n+1)/2];
		}
		
		void input()
		{
			cout<<"\nEnter Upper Triangular elements: ";
			int y;
			for(int i=1; i<=n; ++i)
			{
				for(int j=i; j<=n; ++j)
				{
					cin>>y;
					store(y, i, j);	
				}
			}	
		}
		
		void store(int val, int p1, int p2)
		{
			if(p1<1 || p2<1 || p1>n || p2>n)
			{
				cout<<"\nIndex out of bounds!";
				exit(0);
			}
			else
			{
				int pos = (n*(p1-1))-((p1-2)*(p1-1)/2)+(p2-p1); 
				arr[pos-1] = val;
			}
		}
		
		int retrieve(int p1, int p2)
		{
			if(p1<1 || p2<1 || p1>n || p2>n)
			{
				cout<<"\nIndex out of bounds!";
				exit(0);
			}
			else
			{
				int pos = (n*(p1-1))-((p1-2)*(p1-1)/2)+(p2-p1);
				return arr[pos-1];
			}
		}
		
		void show()
		{
			for(int i=1; i<=n; ++i)
			{
				for(int j=1; j<=n; ++j)
				{
					if(j<i)
						cout<<retrieve(j,i)<<"\t";
					else
						cout<<retrieve(i,j)<<"\t";
				}
				cout<<endl;
			}
		}
};

int main()
{
	Symmetric symm_ob;
	symm_ob.input();
	
	cout<<"\nPrinting the 2-D matrix : \n\n";
	symm_ob.show();
	return 0;
}
