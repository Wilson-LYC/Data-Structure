#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<string>
#include<stdlib.h>
#include <direct.h>
#include <io.h>
#include<shlwapi.h>
using namespace std;

void ChangeColor(int zt, int bj);
void ChangeXY(HANDLE hOut, int x, int y);
void CenterOut(string str, int line, int new_line);
void Change_Window(int width, int height);//行中心输出 str:字符串 line:输出的行数 new_line:1输出后换行 0不换行
string Map_address;
extern void changemap()
{
	string new_map;
	getline(cin, new_map);
	//Change_Window(60, 30);
	again:
	system("cls");
	CenterOut("知行校园导航·更换地图文件", 1, 0);
	CenterOut("===============================================", 2, 1);
	CenterOut("请输入新地图的地址或代码进行操作", 3, 1);
	CenterOut("===============================================", 4, 1);
	CenterOut("输入地址，则修改为地址", 5, 1);
	CenterOut("输入代码，则进行相应操作", 6, 1);
	CenterOut("-----------------------------------------------", 7, 1);
	CenterOut("代码：000，不修改", 8, 1);
	CenterOut("代码：100，修改为广外地图", 9, 1);
	CenterOut("代码：666，修改为演示地图", 10, 1);
	CenterOut("===============================================", 11, 1);
	//cout << "请输入新地图的地址或代码进行操作" << endl;
	//cout << "输入地址，则修改为地址" << endl;
	//cout << "输入代码，则进行相应操作" << endl;
	//cout << "代码：000，不修改" << endl;
	//cout << "代码：100，修改为内置默认地图" << endl;
	///cout << "代码：666，修改为演示地图" << endl;
	//CenterOut("请输入：", 12, 0);
	//cout << "请输入：";
	
	
	fstream txtin;
	do
	{
		CenterOut("                       ", 12, 0);
		CenterOut("请输入：", 12, 0); 
		getline(cin, new_map);
		
		if (new_map == "000")
		{
			return;
		}
		else if (new_map == "666")
		{
			new_map = "D:/Campus navigation/test1.map";
		}
		else if (new_map == "100")
		{
			new_map = "D:/Campus navigation/gdufs.map";
		}
		txtin.open(new_map, ios::in);
		if (!txtin)
		{
			MessageBoxA(NULL, "地址或代码错误，请重新输入", "知行校园导航—错误", MB_OK);
		}
		else cout << "修改成功" << endl;
	}while (!txtin);
	//cout << "修改成功" << endl;
	if (new_map == "000")
	{
		return;
	}
	Map_address = new_map;
	return;
}