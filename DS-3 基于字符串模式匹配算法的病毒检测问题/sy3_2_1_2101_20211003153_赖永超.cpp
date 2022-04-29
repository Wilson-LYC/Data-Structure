#include<iostream>
using namespace std;
int a[101][101];
int ans;
int main()
{
	int n,m,t1,t2;
	cin>>n>>m>>t1>>t2;
	ans=0;
	for (int i=1;i<=t1;i++)
	{
		int x,y,num;
		cin>>x>>y>>num;
		int o=a[x][y];
		a[x][y]+=num;
	}
	for (int i=1;i<=t2;i++)
	{
		int x,y,num;
		cin>>x>>y>>num;
		int o=a[x][y];
		a[x][y]+=num;
	}
	ans=0;
	for (int i=0;i<=n-1;i++)
	{
		for (int j=0;j<=m-1;j++) 
		{
			if(a[i][j]!=0) ans++;
		}
	}
	
	cout<<n<<" "<<m<<" "<<ans<<endl;
	
	for (int i=0;i<=n-1;i++)
	{
		for (int j=0;j<=m-1;j++) 
		{
			if(a[i][j]!=0) cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
		}
	}
}
