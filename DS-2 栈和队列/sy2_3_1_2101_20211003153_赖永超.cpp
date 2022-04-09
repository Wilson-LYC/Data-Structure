#include<iostream>
#include<string.h>
#include<queue>
#include<stack>
#include<math.h>
#include<algorithm>
using namespace std;
int num[1000],nt=0;
char fuhao[1000],ft=0;

int lev(char a)
{
	switch (a)
	{
		case '+': return 0; break;
		case '-': return 0; break;
		case '*': return 1; break;
		case '/': return 1; break;
		case '^': return 2; break;
		case '(': return 3; break;
	}
	return -1;
}

int main()
{
    string s;
    getline(cin,s);	
	int i=0,l=s.length();
    while (i<=l-1)
    {
    	//cout<<"i="<<i<<" s["<<i<<"]="<<s[i]<<endl;
    	if (s[i]>='0'&&s[i]<='9')//是数字
		{
			int new_num=0;
			while (s[i]>='0'&&s[i]<='9')
			{
				new_num=new_num*10+int(s[i])-48;
				i++;
			}
			//cout<<"新数字"<<new_num<<endl;
            nt++;
            num[nt]=new_num;
			//num.push(new_num);//新发现的数字入栈 
		} 
		else //是符号 
		{
			if(s[i]=='(')
			{
                ft++;
                fuhao[ft]=s[i];
				//fuhao.push(s[i]);
			}
			else if (s[i]==')')
			{
				//cout<<"清算"<<endl;
				while (fuhao[ft]!='(')
				{
					int ans=0;	
					int y=num[nt];
					nt--;
					int x=num[nt];
					nt--;
					char op=fuhao[ft];
					ft--;
					switch (op)
					{
						case '+':
							ans=x+y;
							break;
						case '-':
							ans=x-y;
							break;
						case '*':
							ans=x*y;
							break;
						case '/':
							ans=x/y;
							break;
						case '^':
							ans=pow(x,y);
							break;
					}
					//cout<<x<<op<<y<<"="<<ans<<endl;
					nt++;
                    num[nt]=ans;
				}
				ft--;
				//cout<<endl;
			}
			else 
			{
				if (ft==0)
				{
                    ft++;
                    fuhao[ft]=s[i];
					//fuhao.push(s[i]);
				}
				else if (lev(s[i])>lev(fuhao[ft]))
				{
					ft++;
                    fuhao[ft]=s[i];
				}	
				else 
				{
					while (lev(s[i])<=lev(fuhao[ft]))
					{
						if (fuhao[ft]=='(')
						{
							break;
						}
						int ans=0;	
                        int y=num[nt];
                        nt--;
                        int x=num[nt];
                        nt--;
                        char op=fuhao[ft];
                        ft--;
						switch (op)
						{
							case '+':
								ans=x+y;
								break;
							case '-':
								ans=x-y;
								break;
							case '*':
								ans=x*y;
								break;
							case '/':
								ans=x/y;
								break;
							case '^':
								ans=pow(x,y);
								break;
						}
						//cout<<"优先计算"<<endl; 
						//cout<<x<<op<<y<<"="<<ans<<endl;
						if (ft==0) break;
						nt++;
		                num[nt]=ans;
					}
                    ft++;
					fuhao[ft]=s[i];
				} 
			}
			i++; 
		}
	}
	while (nt!=1&&ft>0)
	{
		int ans=0;	
        int y=num[nt];
        nt--;
        int x=num[nt];
        nt--;
        char op=fuhao[ft];
        ft--;
		switch (op)
		{
			case '+':
				ans=x+y;
				break;
			case '-':
				ans=x-y;
				break;
			case '*':
				ans=x*y;
				break;
			case '/':
				ans=x/y;
				break;
			case '^':
				ans=pow(x,y);
				break;
		}
		//cout<<x<<op<<y<<"="<<ans<<endl;
        nt++;
		num[nt]=ans;
	}
	cout<<num[nt];
}
