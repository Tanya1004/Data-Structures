#include<iostream>
#include<time.h>
using namespace std;

template<class T>
void swapping(T& a, T &b)
{
    T temp=a;
    a=b;
    b=temp;
}

template <class T>

class Sorting
{
    T *arr;
    int n;

    public:
    Sorting()
    {

            cout<<"\nEnter no. of elements:";
            cin>>n;
            arr=new T[n];

        cout<<"\nEnter elements:\n";
        for(int i=0; i<n; ++i)
         cin>>arr[i];
    }

    void insertion()
    {
        for(int i=1; i<n; ++i)
        {
            T key=arr[i];
            int j=i-1;

            while(j>=0 && key<arr[j])
            {
                arr[j+1]=arr[j];
                j--;
            }

            arr[j+1]=key;
        }

      }

    void bubble()
    {

        bool swp;
        for(int i=0; i<n; ++i)
        {
            swp=false;
            for(int j=0; j<n-1-i; ++j)
            {
                if(arr[j]>arr[j+1])
                {
                    swapping(arr[j], arr[j+1]);
                    swp=true;
                }
            }

            if(swp==false)
            break;
        }

    }

    void selection()
    {
       int mini;

       for(int i=0; i<n; ++i)
       {
            mini=i;

            for(int j=i+1; j<n; ++j)
            {
                if(arr[j]<arr[mini])
                mini=j;
            }

            if(mini!=i)
            {
                swapping(arr[i], arr[mini]);
            }
        }
    }
    
    void display()
    {
    	for(int y=0; y<n; ++y)
    		cout<<arr[y]<<"  ";
	}
};

int main()
{
   int stype, dtype;

    do
    {
        cout<<"\n\n\t\tMENU";
        cout<<"\n1. Insertion sort";
        cout<<"\n2. Bubble sort";
        cout<<"\n3. Selection sort";
        cout<<"\n4. Exit";

        cout<<"\nEnter your choice: ";
        cin>>stype;

        if(stype==4)
         break;

        do
        {
            cout<<"\n\n\t\tDATA TYPE CHOICE";
            cout<<"\n1. integer";
            cout<<"\n2. character";
            cout<<"\n3. float";
            cout<<"\n4. leave";

            cout<<"\nEnter choice: ";
            cin>>dtype;

            switch(dtype)
            {
                case 1: {
                            Sorting<int> s;

                            if(stype==1)
                                s.insertion();
                            else if(stype==2)
                                s.bubble();
                            else if(stype==3)
                                s.selection();
                            cout<<"\nSorted array: \n";
                            s.display();
							break;
                        }
                case 2: {
                            Sorting<char> s;

                            if(stype==1)
                                s.insertion();
                            else if(stype==2)
                                s.bubble();
                            else if(stype==3)
                                s.selection();
							cout<<"\nSorted array: \n";
                            s.display();
                            break;
                        }
                case 3: {
                            Sorting<float> s;

                            if(stype==1)
                                s.insertion();
                            else if(stype==2)
                                s.bubble();
                            else if(stype==3)
                                s.selection();
							cout<<"\nSorted array: \n";
                            s.display();
                            break;
                        }
                case 4: break;
               default: cout<<"\nWrong choice";
            }
        }while(dtype!=4);

    }while(stype!=4);

    return 0;
}
