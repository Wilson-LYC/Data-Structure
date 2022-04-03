#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>a;
	queue<int>b;
	int n,id;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>id;
		if (id%2==0) b.push(id);
		else a.push(id);
	}

	int t=0,bj=0;
	while (a.size()!=0 || b.size()!=0)
	{
        t++;
		if (a.size()!=0)
		{
			if (bj==1) cout<<" ";
			cout<<a.front();
			a.pop();
			bj=1;
		}
		if (t%2==0 && b.size()!=0)
		{
			if (bj==1) cout<<" ";
			cout<<b.front();
			b.pop();
			bj=1;
		}
        
	}
} 
