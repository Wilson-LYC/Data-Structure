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
#include <vector>
#include<map>
#include<stack>
using namespace std;
void Change_Window(int width, int height);//行中心输出 str:字符串 line:输出的行数 new_line:1输出后换行 0不换行
int road_newmap[101][101];
map<int, string>dian_newmap;
extern void BuildMap()
{
	//Change_Window(60, 50);
	int n, m;
	cout << endl << "知行校园导航·新建地图" << endl;
	cout << "================================================" << endl << endl;
	cout << "开始创建地图" << endl;
	cout << "第一步：录入“点”信息" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "“点”的个数：";
	cin >> n;
	cout << "------------------------------------------------" << endl;
	cout << "请依次输入点的名称，回车确定（例如：又康超市）" << endl;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; i++)
	{
		cout << "点" << i << "：";
		getline(cin, s);
		dian_newmap[i] = s;
	}

	cout << "点信息录入完毕……" << endl;
	Sleep(500);
	system("cls");
	cout << endl << "知行校园导航·新建地图" << endl;
	cout << "================================================" << endl << endl;
	cout << "第二步：录入“边”信息" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "“边”的个数：";
	cin >> m;
	
	for (int i = 1; i <= m; i++)
	{
		system("cls");
		cout << endl << "知行校园导航·新建地图" << endl;
		cout << "================================================" << endl << endl;
		cout << "请依次输入边的信息，回车确认" << endl;
		cout << "！注意：输入时请输入点对应的编号！" << endl;
		cout << endl;
		cout << "序号表" << endl;
		for (auto i : dian_newmap)
		{
			cout << setw(3) << i.first << " " << i.second << endl;
		}
		cout << endl;
		cout << "边" << i << endl;
		cout << "起点：";
		int x, y, l;
		cin >> x;
		cout << "终点：";
		cin >> y;
		cout << "长度：";
		cin >> l;
		road_newmap[x][y] = road_newmap[y][x] = l;
		
	}
	cout << "边信息录入完成……" << endl;
	Sleep(500);
	system("cls");
	cout << endl << "知行校园导航·新建地图" << endl;
	cout << "================================================" << endl << endl;
	cout << "请输入文件名(不带后缀名，例如test)：";
	string filename;
	getline(cin, filename);
	getline(cin, filename);
	cout << "请输入导出的地址，输入000则导出至软件所在根目录" << endl;
	string newmap_address;
	getline(cin, newmap_address);
	if (newmap_address == "000")
		newmap_address = "./" + filename+".map";
	else
		newmap_address = newmap_address + "/" + filename + ".map";
	cout << "创建中……" << endl; 
	Sleep(500);
	system("cls");
	cout << "文件最终地址：" << newmap_address << endl;
	fstream newmap_out;
	newmap_out.open(newmap_address, ios::out);
	newmap_out << n << endl;
	for (int i = 1; i <= n; i++)
	{
		newmap_out << dian_newmap[i] << endl;
	}
	newmap_out << m << endl;
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i - 1; j++)
			newmap_out << i << " " << j << " " << road_newmap[i][j] << endl;
	}
	newmap_out.close();
	cout << "创建完成……" << endl;
	system("pause");
}