#include<iostream>
using namespace std;
typedef struct list
{
    int num;
    struct list *next;
}node,*link;

void input(link &l)
{
    l=new node;
    l->next=NULL;
    int n;
    link r,t;
    r=l;
    do
    {
        cin>>n;
        t=new node;
        t->num=n;
        t->next=NULL;
        r->next=t;
        r=t;
    }while (n!=-1); 
}

int main()
{
    link l1,l2;
    input(l1);
    input(l2);
    link t1,t2;
    t1=l1->next;
    t2=l2->next;
    /*cout<<"begin"<<endl;
	cout<<"1 : "<<t1->num<<endl;
	cout<<"2 : "<<t2->num<<endl;*/
	int bj=0;
    while (t1->next!=NULL && t2->next!=NULL)
	{
		if (t1->num>t2->num)
		{
			t2=t2->next;
		}
		else if (t1->num<t2->num)
		{
			t1=t1->next;
		}
		else
		{
			if (bj==1) cout<<" ";
			cout<<t1->num;
			t1=t1->next;
			t2=t2->next;
			bj=1;
		}
	} 
	if (t1->next==NULL)
	{
		while (t2->next!=NULL)
		{
			if (t2->num==t1->num)
			{
				cout<<t2->num;
			
			}
			t2=t2->next;
		}
	}
	else 
	{
		while (t1->next!=NULL)
		{
			if (t1->num==t2->num)
			{
				cout<<t1->num;
	
			}
			t1=t1->next;
		}
	}
	if (bj==0) cout<<"NULL";
}
