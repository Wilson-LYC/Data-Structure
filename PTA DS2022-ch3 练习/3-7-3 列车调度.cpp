#include<iostream>
#include<queue>
using namespace std;
int q[10000000];
int main()
{
    int n,ans=0,id;
    cin>>n;
    for (int k=1;k<=n;k++)
    {
        cin>>id;
        if (id>q[ans]||ans==0)
        {
        	ans++;
        	q[ans]=id;
		} 
		else 
		{
			int x=1,y=ans;
			while (x<=y)
			{
				//cout<<x<<"->"<<y<<endl; 
				if (id<=q[(x+y)/2])
				{
					y=(x+y)/2-1;
				}
				else 
				x=(x+y)/2+1;
			} 
			q[x]=id;
		}
		
    }
    cout<<ans;
}
