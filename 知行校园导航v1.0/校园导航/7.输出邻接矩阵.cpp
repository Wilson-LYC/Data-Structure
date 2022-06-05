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
int road1[101][101];
map<int, string>dian1;
extern void print_ljjz(string Map_address)
{
	cout << endl << "知行校园导航·输出邻接矩阵" << endl;
	cout << "================================================" << endl << endl;
	//Change_Window(60, 50);
	fstream txtin2;
	txtin2.open(Map_address, ios::in);
	int n, m;
	txtin2 >> n;
	string s;
	getline(txtin2, s);
	for (int i = 1; i <= n; i++)
	{
		getline(txtin2, s);
		dian1[i] = s;
	}

	txtin2 >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		txtin2 >> x >> y >> l;
		road1[x][y] = road1[y][x] = l;
	}
	txtin2.close();
	cout << "序号表" << endl;
	cout << "------------------------------------------------" << endl;
	for (auto i : dian1)
	{
		cout << setw(3) << i.first << " " << i.second << endl;
	}
	cout << endl<<"================================================" << endl<<endl;
	cout << "邻接矩阵" << endl;
	cout << setw(3) << "";
	for (int i = 1; i <= n; i++) cout << setw(3) << i;
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << setw(3) << i;
		for (int j = 1; j <= n; j++)
		{
			if (road1[i][j] > 0)
				cout << setw(3) << 1;
			else cout << setw(3) << 0;
		}
		cout << endl;
	}
	system("pause");
}