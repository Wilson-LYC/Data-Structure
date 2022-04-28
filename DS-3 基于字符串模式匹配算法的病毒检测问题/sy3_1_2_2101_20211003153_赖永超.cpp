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
int next[600];

void Next(string s)
{
	int i;
	for (i=0;i<=500;i++) next[i]=0;
    int j=0;i=1;
    while (i<s.length())
    {
    	if (j==0||s[i]==s[j])
    	{
    		++i;
    		++j;
    		next[i]=j;
		}
		else j=next[j];
	}
}

int KMP(string a,string b)
{
    int i=0,j=1;
    while (i<=a.length()&&j<=b.length())
    {
    	if (j==0||a[i]==b[j])
    	{
    		++i;
    		j++;
		}
		else j=next[j];
	}
	if (j>b.length()) return i-b.length();
	else return 0;
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
        	Next(a);
        	if (KMP(s,a)!=0)
			{
				bj=1;
				cout<<"YES"<<endl;
				break;
			}
		}
		if (bj==0) cout<<"NO"<<endl; 
	}
}
