#include<iostream>
using namespace std;

class term
{
    public:
    float coeff;
    int expo;
    term*next;

    term()
    {
        next=NULL;
    }
};

class Polynomial
{
    term*first;

    public:
    Polynomial()
    {
        first=NULL;
    }

    void insert_sorted(float c, int e)
    {
        term*newterm=new term;
        newterm->coeff=c;
        newterm->expo=e;

        if(first==NULL||first->expo<=e)
        {
            newterm->next=first;
            first=newterm;
        }
        else
        {
            term*t=first;
            while(t->next!=NULL && t->next->expo>e)
            {
                t=t->next;
            }

            newterm->next=t->next;
            t->next=newterm;
        }
    }

    void addition(Polynomial sl1)
    {
        term*p1=first;
        term*p2=sl1.first;

        Polynomial s3;
        //term*p3=s3->first;

        float c;
        int ex;

        while(p1!=NULL&&p2!=NULL)
        {
            if(p1->expo==p2->expo)
            {
                c=(p1->coeff)+(p2->coeff);
                ex=p1->expo;
                s3.insert_sorted(c, ex);
                p1=p1->next;
                p2=p2->next;
            }
            else if(p1->expo>p2->expo)
            {
                c=p1->coeff;
                ex=p1->expo;
                s3.insert_sorted(c, ex);
                p1=p1->next;
            }
            else if(p2->expo>p1->expo)
            {
                c=p2->coeff;
                ex=p2->expo;
                s3.insert_sorted(c, ex);
                p2=p2->next;
            }
        }

        while(p1!=NULL)
        {
            c=p1->coeff;
            ex=p1->expo;
            s3.insert_sorted(c, ex);
            p1=p1->next;
        }

        while(p2!=NULL)
        {
            c=p2->coeff;
            ex=p2->expo;
            s3.insert_sorted(c, ex);
            p2=p2->next;
        }

        cout<<"\nRESULTANT POLYNOMIAL : ";
		s3.show_poly();
    }

    void show_poly()
    {
        if(first==NULL)
            cout<<"\nNO ENTRY IN POLYNOMIAL!"<<endl;
        else
        {
            term*tmp=first;
            while(tmp!=NULL)
            {
                cout<<"("<<tmp->coeff<<") x^"<<tmp->expo;
                if(tmp->next!=NULL)
                cout<<" + ";
                tmp=tmp->next;
            }
        }
    }
};

int main()
{
    Polynomial l[2], l3;

    float co;
    int x;
    char c='y';

    for(int i=0; i<2; ++i)
    {
        cout<<"\nENTER POLYNOMIAL "<<i+1<<endl;
        do
        {
            cout<<"\nCOEFFICIENT: ";
            cin>>co;
            cout<<"\nEXPONENT:    ";
            cin>>x;

            l[i].insert_sorted(co, x);
            cout<<"\n\nEnter another term? ";
            cin>>c;
        }while(c=='y'||c=='Y');

        cout<<"\nENTERED POLYNOMIAL:  ";
        l[i].show_poly();
        cout<<endl;
    }

    l[0].addition(l[1]);
    cout<<endl;

    return 0;
}
