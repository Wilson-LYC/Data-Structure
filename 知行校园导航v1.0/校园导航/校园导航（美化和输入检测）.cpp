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
using namespace std;

void FirtstUse();
void ChangeColor(int zt, int bj);
void ChangeXY(HANDLE hOut, int x, int y);
void CenterOut(string str, int line, int new_line);
void Change_Window(int width, int height);//行中心输出 str:字符串 line:输出的行数 new_line:1输出后换行 0不换行
void changemap();
void PtP(string Map_address, int begin, int end);
void print_ljjz(string Map_address);
void print_ljb(string Map_address);
void BuildMap();
void AllRoad(string Map_address);
void arrive_all(string Map_address);
void AllRoad_dian(string Map_address);
int ck_w_size();//返回窗口宽度
int main()
{
	FirtstUse();//第一次使用，建立默认地图和相关配置文件
	
	extern string Map_address;//地图地址

	//加载地图
	{
		Map_address = "D:/Campus navigation/gdufs.map";
	}
	
	while (1)
	{
		int choice;
		system("cls");
		//输出交互文字
		{
			CenterOut("知行校园导航", 1, 0);
			//cout << "知行校园导航" << endl;
			CenterOut("===============================================", 2, 1);
			CenterOut("基本信息", 3, 0);
			//cout << "基本信息" << endl;
			//cout << "----------------------------------------" << endl;
			CenterOut("-----------------------------------------------", 4, 1);
			string text = "地图文件: " + Map_address;
			CenterOut(text,5, 1);
			//cout << "地图文件：" << Map_address << endl;
			//cout << endl;

			CenterOut("操作", 7, 1);
			CenterOut("===============================================", 8, 1);
			CenterOut("导航", 9, 1);
			CenterOut("-----------------------------------------------", 10, 1);
			CenterOut("1.“点到点”导航                    ", 11, 1);
			CenterOut("2.从某点出发，打卡所有点的路径      ", 12, 1);
			CenterOut("3.输出所有点到其它点的最短距离和路径", 13, 1);
			CenterOut("4.某点到其它点的最短距离和路径      ", 14, 1);

			//cout << "导航" << endl;
			//cout << "----------------------------------------" << endl;
			//cout << "1.“点到点”导航" << endl;
			//cout << "2.从某点出发，打卡所有点" << endl;
			//cout << "3.输出所有点到其它点的最短距离" << endl;
			//cout << "4.某点到其它点的最短距离" << endl;


			CenterOut("设置", 16, 1);
			CenterOut("-----------------------------------------------", 17, 1);
			CenterOut("5.更换地图文件", 18, 1);
			CenterOut("6.新建地图文件", 19, 1);
			CenterOut("7.输出邻接矩阵", 20, 1);
			CenterOut("8.输出邻接表  ", 21, 1);


			/*cout << "设置" << endl;
			cout << "----------------------------------------" << endl;
			cout << "5.更换地图文件" << endl;
			cout << "6.新建地图文件" << endl;
			cout << "7.输出邻接矩阵" << endl;
			cout << "8.输出邻接表" << endl;
			cout << endl;*/
			CenterOut("Developers: Lai Yongchao & Long Xiaocong", 28, 0);
			CenterOut("===============================================", 22, 1);
			CenterOut("0.退出", 23, 1);
			//cout << "0.退出" << endl<<endl;
			//CenterOut("666.开发者信息", 24, 1);
			CenterOut("===============================================", 24, 1);
			CenterOut("输入数字，选择操作，回车确认", 25, 1);
			CenterOut("请输入:", 26, 0);
			//cout << "输入数字，选择操作，回车确认" << endl;
			//cout << "请输入:";
			cin >> choice;
		}

		if (choice == 0)//选择0，退出系统
		{
			int check_exit=MessageBoxA(NULL,("您是否要退出本系统"), ("退出导航"), MB_OKCANCEL);
			if (check_exit == 1) exit(1);
		}else 
		if (choice == 1)//1.“点到点”导航
		{
			system("cls");
			PtP(Map_address,-1,-1);
		}else 
		if (choice == 2)//2.从某点出发，打卡所有点
		{
			system("cls");
			arrive_all(Map_address);
		}else
		if (choice == 3)//3.输出所有点到其它点的最短距离
		{
			system("cls");
			AllRoad(Map_address);
		}
		else
		if (choice == 4)//4.某点到其它点的最短距离
		{
			system("cls");
			AllRoad_dian(Map_address);
		}
		else
		if (choice == 5)//5.更换地图文件
		{
			system("cls");
			changemap();
			
		}
		else
		if (choice == 6)//6.新建地图文件
		{
			system("cls");
			BuildMap();
			
		}
		else
		if (choice == 7)//7.输出邻接矩阵
		{
			system("cls");
			print_ljjz(Map_address);
			
		}
		else
		if (choice == 8)//8.输出邻接表
		{
			system("cls");
			print_ljb(Map_address);
		}else
		{
			system("cls");
			CenterOut("知行校园导航", 1, 1);
			CenterOut("+----------------------+", 2, 1);
			CenterOut("|         警告         |", 3, 1);
			CenterOut("+----------------------+", 4, 1);
			CenterOut("|                      |", 5, 1);
			CenterOut("|       无效输入       |", 6, 1);
			CenterOut("|      请重新输入      |", 7, 1);
			CenterOut("|                      |", 8, 1);
			CenterOut("+----------------------+", 9, 1);
			system("pause");
		}
	}
	return 0;
}