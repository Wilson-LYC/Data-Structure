#include<iostream>
using namespace std;
typedef struct list
{
    int num;
    struct list *next;
}node,*link;
int all=0;
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
        if (n!=-1) all++;
    }while (n!=-1); 
}

int main()
{
    link l1,l2,l3;
    input(l1);
    input(l2);
	if (all==0)
    {
    	cout<<"NULL";
    	return 0;
	}
    link t1,t2,t3;
    t1=l1->next;
    t2=l2->next;
    l3=new node;
    l3->next=NULL;
    if (t1->num>t2->num) 
    {
    	l3->next=t2;
    	t2=t2->next;
	}
    else 
    {
    	l3->next=t1;
    	t1=t1->next;
	}
	t3=l3->next;
	//cout<<"begin t3="<<t3->num<<endl;
    while (t1->next!=NULL && t2->next!=NULL)
	{
		//cout<<"t1="<<t1->num<<" t2="<<t2->num<<endl;
		if (t1->num>t2->num)//min : t2,link to t2
		{	
			t3->next=t2;
			t3=t2;
			t2=t2->next;
			t3->next=NULL;
			//cout<<"t3="<<t3->num<<endl;
		}
		else if (t1->num<=t2->num)
		{
			t3->next=t1;
			t3=t1;
			t1=t1->next;
			t3->next=NULL;
			//cout<<"t3="<<t3->num<<endl;
		}
	} 
	
	if (t1->next==NULL)
	{
		while (t2->next!=NULL)
		{
			//cout<<t2->num<<" ";
			t3->next=t2;
			t3=t2;
			t2=t2->next;
			//t3->next=NULL;
					
		}
	}
	else 
	{
		while (t1->next!=NULL)
		{
			//cout<<t1->num<<" ";
			t3->next=t1;
			t3=t1;
			t1=t1->next;
			//t3->next=NULL;		
		}
	}
	t3=l3->next;
	int bj=0;
	while (t3->next!=NULL)
	{
		if (bj==1) cout<<" ";
		cout<<t3->num;
		bj=1;	
		t3=t3->next;
	}
	if (bj==0) cout<<"NULL";
}
