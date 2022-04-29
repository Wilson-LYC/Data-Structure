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
int nnext[600];

void nNext(string s)
{
	int i;
	for (i=0;i<=s.length();i++) nnext[i]=0;
	nnext[1]=0;
    int j=0;
	i=1;
    while (i<s.length())
    {
		//cout<<s[i]<<" "<<s[j]<<endl;
    	if (j==0||s[i]==s[j])
    	{
    		++i;
    		++j;
    		if (s[i]!=s[j]) nnext[i]=j;
    		else nnext[i]=nnext[j];
    		//nnext[i]=j;
		}
		else j=nnext[j];
	}
}

int KMP(string a,string b)
{
    int i=0,j=0;
    while (i<=a.length()-1&&j<=b.length()-1)
    {
    	//cout<<a[i]<<" "<<b[j]<<endl;
    	if (j==0 || a[i]==b[j])
    	{
    		++i;
    		++j;
		}
		else j=nnext[j];
	}
	if (j>b.length()-1)
	{
		//cout<<"匹配成功"; 
		return i-b.length()-1;
	 } 
	else
	{
		//cout<<"匹配失败"; 
		return -1;
	} 
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
        	//cout<<a;
        	nNext(a);
        	if (KMP(s,a)!=-1)
			{
				bj=1;
				cout<<"YES"<<endl;
				break;
			}
			//else cout<<" NO"<<endl; 
		}
		if (bj==0) cout<<"NO"<<endl; 
	}
}
