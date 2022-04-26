/*
学号：20211003153
姓名：赖永超
班级：计算机2101
版本：V1.0 
GitHub：https://github.com/Wilson-LYC/Data-Structure
*/
#include<iostream>
#include<string.h>
using namespace std;
int str_find(string s,string p)
{
    int ls=s.length(),lp=p.length();
	if (lp>ls) return -1; 
    for (int i=0;i<=ls-lp;i++)
    {
    	//cout<<"-----"<<endl;
    	int bj=0;
    	for (int j=0;j<=lp-1;j++)
    	{
    		//cout<<s[i+j]<<" "<<p[j]<<endl;
    		if (s[i+j]!=p[j])
    		{
    			bj=1;
    			break;
			}
		}
		if (bj==0)
		{
			return i;
		}
	}
	return -1;
}
int main()
{
	int n;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		string s,x;
		cin>>x>>s;
        //cout<<s<<" "<<x<<endl;
        int lx=x.length()-1;
        x+=x;
        int bj=0;
        for (int j=0;j<=lx;j++)
        {
        	string a=x.substr(j,lx+1);
        	//cout<<a<<endl;
        	if (str_find(s,a)!=-1)
			{
				cout<<"YES";cout<<endl;
				bj=1;
				break;
	        }
		}
		if (bj==0) cout<<"NO"<<endl; 
	}
}
