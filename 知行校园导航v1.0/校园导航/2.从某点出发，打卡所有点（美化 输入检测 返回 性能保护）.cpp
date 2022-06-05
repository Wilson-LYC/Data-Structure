#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <sstream>
#include <conio.h> 
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <errno.h>
#include<map>
#include<stack>
using namespace std;
void CenterOut(string str, int line, int new_line);
int old_road[101][101];
int final_road[101][101];//存储着常规值和新建边 
int temp_road[101][101]; //存储着点与点之间的最小值 
int Arrival_mark[101];
map<int, string>dian_m;//记录点信息 
stack<int>final_m;//最终路径 
stack<int>temp_m;//缓存路径 
int temp_long, final_long;
void Change_Window(int width, int height);
void find_all(int x, int end, int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		sum += Arrival_mark[i];
	}
	if (sum == n)
	{
		//cout << "抵达了" << sum << "个点" << endl;
		temp_long = 0;
		//逆转栈 
		stack<int>shunxu;
		stack<int>output;
		shunxu = temp_m;
		while (shunxu.size() > 0)
		{
			output.push(shunxu.top());
			shunxu.pop();
		}
		int last = end;
		//cout<<dian_m[end];
		while (output.size() > 0)
		{

			temp_long += final_road[last][output.top()];
			//cout<<" ---"<<final_road[last][output.top()]<<"---> "<<dian_m[output.top()];
			last = output.top();
			output.pop();

		}
		temp_long += final_road[last][end];
		//cout<<" ---"<<final_road[last][end]<<"---> "<<dian_m[end]<<endl;
		//cout<<"-------------------------------------"<<endl; 
		//cout<<"总路程："<<temp_long<<" 现有最小路程："<<final_long<<endl;


		if (temp_long < final_long)
		{
			final_long = temp_long;
			final_m = temp_m;
		}
		temp_long -= final_road[temp_m.top()][end];
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (final_road[x][i] != 999999 && Arrival_mark[i] == 0)//存在道路且未到达过 
			{
				Arrival_mark[i] = 1;
				temp_m.push(i);
				//temp_long+=final_road[x][i];

				find_all(i, end, n);

				//temp_long-=final_road[x][i];
				temp_m.pop();
				Arrival_mark[i] = 0;
			}
		}
	}
}

void build(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				//cout<<temp_road[i][j]<<" VS "<<temp_road[i][k]+temp_road[k][j]<<endl;
				temp_road[i][j] = min(temp_road[i][j], temp_road[i][k] + temp_road[k][j]);
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			if (final_road[i][j] == 999999)
			{
				//cout<<"build"<<endl;
				final_road[i][j] = temp_road[i][j];
			}
		}
	}
}

void find_normal(int x, int end, int n)
{
	if (x == end)
	{
		if (temp_long < final_long)
		{

			final_long = temp_long;
			final_m = temp_m;
		}
		//cout<<endl;
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (old_road[x][i] != 999999 && Arrival_mark[i] == 0)//存在道路且未到达过 
			{
				Arrival_mark[i] = 1;
				temp_m.push(i);
				temp_long += old_road[x][i];

				find_normal(i, end, n);
				temp_long -= old_road[x][i];
				temp_m.pop();
				Arrival_mark[i] = 0;
			}
		}
	}
}

extern void arrive_all(string Map_address)
{
	//freopen("in.txt", "r", stdin);
	fstream mapin;
	mapin.open(Map_address, ios::in);
	int n, m;
	mapin >> n;
	if (n > 10)//性能保护
	{
		MessageBoxA(NULL, "本功能不支持节点数大于10的地图", "错误：节点数大于10", MB_OK);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			final_road[i][j] = final_road[j][i] = 999999;
			old_road[i][j] = old_road[j][i] = 999999;
			temp_road[i][j] = temp_road[j][i] = 999999;
		}
	}
	string s;
	getline(mapin, s);
	for (int i = 1; i <= n; i++)
	{
		getline(mapin, s);
		dian_m[i] = s;
	}
	mapin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		mapin >> x >> y >> l;
		final_road[x][y] = l;
		final_road[y][x] = l;
		temp_road[x][y] = l;
		temp_road[y][x] = l;
		old_road[x][y] = l;
		old_road[y][x] = l;
	}

	CenterOut("知行校园导航·从某点出发，打卡所有点的路径", 1, 0);
	CenterOut("===============================================", 2, 1);
	int oline = 2;
	oline++;
	CenterOut("[节点名称]", oline, 0);
	cout << " ------- " << "[编号]" << endl;
	for (auto i : dian_m)
	{
		//cout << setw(10) << i.first << " " << i.second << endl;
		oline++;
		//string text = to_string(i.first);
		CenterOut(i.second, oline, 0);
		cout << " ------- " << i.first << endl;
	}

	//cout << "请输入起点：";
	int begin;
	oline++;
	CenterOut("===============================================", oline, 1);
	oline++;
	CenterOut("* 输入0，返回上一级 *", oline, 0);
	oline += 2;
	do
	{
		CenterOut("                                            ", oline, 0);
		CenterOut("请输入起点编号：", oline, 0);
		cin >> begin;
		if (begin == 0) return;
		if (dian_m.count(begin) == 0)
		{
			MessageBoxA(NULL, "此点不存在，请重新输入！", "知行校园导航—错误", MB_OK);
		}
	} while (dian_m.count(begin) == 0);

	temp_long = 0; final_long = 999999999;
	Arrival_mark[begin] = 1;

	build(n);

	/*cout << "序号表" << endl;
	for(auto i:dian_m)
	{
		cout<<setw(3)<<i.first<<" "<<i.second<<endl;
	}
	cout<<setw(7)<<"";
	for (int i=1;i<=n;i++) cout<<setw(7)<<i;
	cout<<endl;
	for (int i=1;i<=n;i++)
	{
		cout<<setw(7)<<i;
		for (int j=1;j<=n;j++)
		{
			if (final_road[i][j]==999999) cout<<setw(7)<<"X";
			else cout<<setw(7)<<final_road[i][j];
		}
		cout<<endl;
	}*/


	find_all(begin, begin, n);

	{
		system("cls");
		//整体输出 
		cout << endl << "知行校园导航·从某点出发，打卡所有点的路径" << endl;
		cout << "================================================" << endl<<endl;
		cout << "大致方向" << endl;
		cout << "------------------------------------------------" << endl;
		stack<int>shunxu;
		stack<int>output;
		shunxu = final_m;
		while (shunxu.size() > 0)
		{
			output.push(shunxu.top());
			shunxu.pop();
		}
		int last = begin;
		cout << dian_m[begin];
		while (output.size() > 0)
		{
			cout << " ------> " << dian_m[output.top()];
			last = output.top();
			output.pop();

		}
		cout << " ------> " << dian_m[begin] << endl;
	}
	cout << endl;
	cout << "详细路径" << endl;
	cout << "------------------------------------------------" << endl;
	//细节输出 
	stack<int>shunxu;
	while (final_m.size() > 0)
	{
		shunxu.push(final_m.top());
		final_m.pop();
	}


	int last = begin;
	cout << dian_m[last];
	//cout<<endl;
	while (shunxu.size() > 0)
	{
		//cout<<last<<"->"<< shunxu.top()<<"++++"<<endl;
		//last--->shunxu.top()
		//初始化 
		temp_long = 0; final_long = 999999999;
		memset(Arrival_mark, 0, sizeof(Arrival_mark));
		temp_m.empty();
		final_m.empty();
		Arrival_mark[last] = 1;
		find_normal(last, shunxu.top(), n);
		//逆转栈 
		stack<int>output;
		while (final_m.size() > 0)
		{
			output.push(final_m.top());
			final_m.pop();
		}
		//int llast=last; 
		while (output.size() > 0)
		{
			//lop = output.top();
			cout << " ------> " << dian_m[output.top()];
			output.pop();
		}
		last = shunxu.top();
		shunxu.pop();
	}
	temp_long = 0; final_long = 999999999;
	memset(Arrival_mark, 0, sizeof(Arrival_mark));
	int bjj=temp_m.empty();
	bjj=final_m.empty();
	Arrival_mark[last] = 1;
	find_normal(last, begin, n);
	stack<int>output;
	while (final_m.size() > 0)
	{
		output.push(final_m.top());
		final_m.pop();
	}
	while (output.size() > 0)
	{
		cout << " ------> " << dian_m[output.top()];
		//last=output.top();
		output.pop();
	}
	cout << endl<<endl;
	//fclose(stdin);
	system("pause");
}