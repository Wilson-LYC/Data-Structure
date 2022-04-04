#include<iostream>
using namespace std;
struct list
{
	int id;
	int next,last; 
} a[3001];
int main()
{
	int n,p,t=1,i;
	cin>>n>>p;
	for (i=1;i<=n-1;i++)
	{
		a[i].last=i-1;
		a[i].id=i;
		a[i].next=i+1;
	}
	a[1].last=n;
	a[i].id=i;
	a[i].next=1;
	a[i].last=n-1;
	int o=0,k=n;
	
	int bj=0;
	while (k!=0)
	{
		o++;
		//cout<<t<<"±¨Êý£º"<<o%p<<endl;
		if (o%p==0)
		{
			k--;
			//cout<<"!Ìß³ö: ";
			if (bj==1) cout<<" ";
			cout<<t;
			bj=1;
			a[t].id=-100;
			//cout<<endl<<endl;
			a[a[t].last].next=a[t].next;
			a[a[t].next].last=a[t].last;
			for (int j=1;j<=n;j++)
			{
				//cout<<a[j].last<<"->"<<a[j].id<<"->"<<a[j].next<<endl;
			}
		}
		t=a[t].next;
		//cin>>i;
	}
} 
