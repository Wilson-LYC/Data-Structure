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

void xxbl(int id)
{
	cout<<code[id].me<<" ";
	if (code[id].lson!=0) xxbl(code[id].lson);
	if (code[id].rson!=0) xxbl(code[id].rson);
}
void zxbl(int id)
{
	if (code[id].lson!=0) zxbl(code[id].lson);
	cout<<code[id].me<<" ";
	if (code[id].rson!=0) zxbl(code[id].rson);
}
void hxbl(int id)
{
	if (code[id].lson!=0) hxbl(code[id].lson);	
	if (code[id].rson!=0) hxbl(code[id].rson);
	cout<<code[id].me<<" ";
}
int ceng[15][2000],maxc=0;
void csbl(int id,int c)
{
	if (maxc<c) maxc=c;
	ceng[c][0]++;
	int num=ceng[c][0];
	ceng[c][num]=id;
	if (code[id].lson!=0) csbl(code[id].lson,c+1);
	if (code[id].rson!=0) csbl(code[id].rson,c+1);
}

int main()
{
	cin>>s;
	for (int i=1;i<=101;i++)
    {
        code[i].me='#';
        code[i].lson=code[i].rson=0;
    }
    t=-1;
	p=0;
	build();
	cout<<"前序遍历：";
	xxbl(1);
	cout<<endl;
	cout<<"中序遍历：";
	zxbl(1);
	cout<<endl;
	cout<<"后序遍历：";
	hxbl(1);
	cout<<endl;
	cout<<"层序遍历："<<endl;
	csbl(1,1);
	for (int i=1;i<=maxc;i++)
	{
		cout<<i<<" : ";
		for (int j=1;j<=ceng[i][0];j++) cout<<code[ceng[i][j]].me<<" ";
		cout<<endl;
	}
    cout<<endl;
        
    /*for (int i=1;i<=p;i++)
    {
    	cout<<code[i].me<<" lson="<<code[code[i].lson].me<<" rson="<<code[code[i].rson].me<<endl;
	}*/

	
} 
