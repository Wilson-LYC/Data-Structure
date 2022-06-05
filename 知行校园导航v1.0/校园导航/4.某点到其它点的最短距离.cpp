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
#include <stack>
#include <map>
using namespace std;
void CenterOut(string str, int line, int new_line);
int road_AllRoad1[101][101];
int bj_AllRoad1[101];
map<int, string>dian_AllRoad1;
stack<int>final_AllRoad1;
stack<int>temp_AllRoad1;
int minn_AllRoad1, ans_AllRoad1;
void Change_Window(int width, int height);

extern void find_AllRoad1(int x, int end, int n)
{
	if (x == end)
	{ 
		if (minn_AllRoad1 < ans_AllRoad1)
		{
			ans_AllRoad1 = minn_AllRoad1;
			final_AllRoad1 = temp_AllRoad1;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (road_AllRoad1[x][i] > 0 && bj_AllRoad1[i] == 0)//存在道路且未到达过 
			{
				bj_AllRoad1[i] = 1;
				temp_AllRoad1.push(i);
				minn_AllRoad1 += road_AllRoad1[x][i];

				find_AllRoad1(i, end, n);
				minn_AllRoad1 -= road_AllRoad1[x][i];
				temp_AllRoad1.pop();
				bj_AllRoad1[i] = 0;
			}
		}
	}
}

extern void AllRoad_dian(string Map_address)
{
	//Change_Window(60,50);
	/*cout << "信息将输出到文件“所有最短路.txt”中，请在软件所在根目录中查看此文件" << endl;
	fstream allroad_out;
	allroad_out.open("./所有最短路.txt", ios::out);*/
	fstream allroad_in;
	allroad_in.open(Map_address, ios::in);

	//获取信息
	int n, m;
	allroad_in >> n;
	string s;
	getline(allroad_in, s);
	for (int i = 1; i <= n; i++)
	{
		getline(allroad_in, s);
		dian_AllRoad1[i] = s;
	}

	allroad_in >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		allroad_in >> x >> y >> l;
		road_AllRoad1[x][y] = l;
		road_AllRoad1[y][x] = l;
	}
	allroad_in.close();

	//

	CenterOut("知行校园导航·某点到其它点的最短距离和路径", 1, 0);
	CenterOut("===============================================", 2, 1);
	int oline = 2;
	oline++;
	CenterOut("[节点名称]", oline, 0);
	cout << " ------- " << "[编号]" << endl;
	for (auto i : dian_AllRoad1)
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
		if (dian_AllRoad1.count(begin) == 0)
		{
			MessageBoxA(NULL, "此点不存在，请重新输入！", "知行校园导航—错误", MB_OK);
		}
	} while (dian_AllRoad1.count(begin) == 0);



	system("cls");
	cout << endl << "知行校园导航·某点到其它点的最短距离和路径" << endl;
	cout << "================================================" << endl << endl;

	for (int end = 1; end <= n; end++)
	{
		if (begin == end) continue;
		cout << "方向: " << dian_AllRoad1[begin] << " <===> " << dian_AllRoad1[end] << endl;
		cout << "================================================" << endl;
		minn_AllRoad1 = 0; ans_AllRoad1 = 999999999;
		memset(bj_AllRoad1, 0, sizeof(bj_AllRoad1));
		bj_AllRoad1[begin] = 1;
		find_AllRoad1(begin, end, n);
		stack<int>output;
		while (final_AllRoad1.size() > 0)
		{
			output.push(final_AllRoad1.top());
			final_AllRoad1.pop();
		}
		int last = begin;
		
		cout << "具体路径: " << dian_AllRoad1[begin];
		while (output.size() > 0)
		{
			
			cout << " <--" << road_AllRoad1[last][output.top()] << "--> " << dian_AllRoad1[output.top()];
			last = output.top();
			output.pop();
		}
		
		cout << endl;
		cout << "------------------------------------------------" << endl;
		
		
		cout << "总长度：" << ans_AllRoad1 << endl;
		cout << endl;
		
		cout << endl;
	}
	system("pause");
}
