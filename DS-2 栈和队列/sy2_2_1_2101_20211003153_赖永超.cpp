#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
int main()
{
	stack<int>num;
	string s;
	getline(cin,s);
	int l=s.length(),i=0;
	while (i<=l-1)
	{
		//cout<<"i="<<i<<endl;
		if (s[i]>='0' && s[i]<='9')
		{
			int new_num=0;
			while (s[i]>='0' && s[i]<='9')
			{
				new_num=new_num*10+int(s[i])-48;
				i++;
			} 
			num.push(new_num);
		}	
		else if (s[i]!=' ') 
		{
			int a,b,ans=0;
			a=num.top();
			num.pop();
			b=num.top();
			num.pop();
			switch (s[i])
			{
				case '+':
					ans=a+b;
					break;
				case '-':
					ans=b-a;
					break;
				case '*':
					ans=a*b;
					break;
				case '/':
					ans=b/a;
					break;
			}
			//cout<<a<<s[i]<<b<<"="<<ans<<endl; 
			num.push(ans);
		}
		i++;
	} 
	cout<<num.top();
} 
