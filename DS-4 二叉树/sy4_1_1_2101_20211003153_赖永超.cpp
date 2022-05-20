/*
学号：20211003153
姓名：赖永超
班级：计算机2101
版本：V1.0 
GitHub：https://github.com/Wilson-LYC/Data-Structure
*/
#include<iostream>
using namespace std;
string s;
int t;
struct tree
{
	int lson,rson;
	char me;
}code[1001];
int p=0;

void build()
{
	t++;
	char next=s[t];
	if (next=='#')
	{
		return;
	}
	else 
	{
		int dad;
		p++;
		dad=p;
		code[dad].me=next; 
		if (s[t+1]!='#')
		{ 	
			code[dad].lson=p+1;
			build();
		} else t++;
		if (s[t+1]!='#')
		{
			code[dad].rson=p+1;
			build();
		}else t++;
		return;
	}
}

void output(int id)
{
	if (code[id].lson!=0) output(code[id].lson);
	cout<<code[id].me<<" ";
	if (code[id].rson!=0) output(code[id].rson);
}
int main()
{
	while (cin>>s)
    {
        for (int i=1;i<=101;i++)
        {
            code[i].me='#';
            code[i].lson=code[i].rson=0;
        }
        t=-1;
	    p=0;
	    build();
	    output(1);
        cout<<endl;
        
        /*for (int i=1;i<=p;i++)
        {
        	cout<<code[i].me<<" lson="<<code[code[i].lson].me<<" rson="<<code[code[i].rson].me<<endl;
		}*/
    }
	
} 
