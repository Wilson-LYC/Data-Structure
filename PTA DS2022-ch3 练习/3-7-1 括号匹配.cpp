#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char stack[1000];
	char s[1000];
	cin.getline(s,1000);
	int l=strlen(s);
	int bj=1,t=0;
	for (int i=1;i<=l-1;i++)
	{
		if (s[i]=='('||s[i]=='['||s[i]=='{')
		{
			t++;
			stack[t]=s[i];
		}
		if (s[i]==')'||s[i]==']'||s[i]=='}')
		{
			if (s[i]-stack[t]==1&&t>0)
			{
				t--;
			}
			else bj=0;
		}
	}
	if (bj==1 && t==0) cout<<"yes";
	else cout<<"no";
} 
