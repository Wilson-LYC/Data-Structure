#include<iostream>
#include<queue>
using namespace std;
int main()
{
	queue<int>a;
	queue<int>b;
	int n,id;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>id;
		if (id%2==0) b.push(id);//顾客编号为偶数，到b窗口的队列中
		else a.push(id);//顾客编号为奇数，到a窗口的队列中
	}

	int t=0,bj=0;//t记录时间，bj记录是否要输出空格
	while (a.size()!=0 || b.size()!=0)
	{
        t++;
		if (a.size()!=0)//每1s，当a队列不为空时，a队列出队一个
		{
			if (bj==1) cout<<" ";
			cout<<a.front();
			a.pop();
			bj=1;
		}
		if (t%2==0 && b.size()!=0)//每2s，当b队列不为空时，b队列出队一个
		{
			if (bj==1) cout<<" ";
			cout<<b.front();
			b.pop();
			bj=1;
		}
        
	}
} 
