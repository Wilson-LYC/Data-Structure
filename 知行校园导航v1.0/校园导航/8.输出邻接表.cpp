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
void Change_Window(int width, int height);//��������� str:�ַ��� line:��������� new_line:1������� 0������
int road2[101][101];
map<int, string>dian2;
extern void print_ljb(string Map_address)
{
	cout << endl << "֪��У԰����������ڽӱ�" << endl;
	cout << "================================================" << endl << endl;
	//Change_Window(60, 50);
	fstream txtin3;
	txtin3.open(Map_address, ios::in);
	int n, m;
	txtin3 >> n;
	string s;
	getline(txtin3, s);
	for (int i = 1; i <= n; i++)
	{
		getline(txtin3, s);
		dian2[i] = s;
	}

	txtin3 >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		txtin3 >> x >> y >> l;
		road2[x][y] = road2[y][x] = l;
	}
	txtin3.close();
	cout << "��ű�" << endl;
	cout << "------------------------------------------------" << endl;
	for (auto i : dian2)
	{
		cout << setw(3) << i.first << " " << i.second << endl;
	}
	cout << endl << "================================================" << endl << endl;
	cout << "�ڽӱ�" << endl;
	for (int i = 1; i <= n; i++)
	{
		cout << setw(3)<<i - 1 << " ";
		cout << i;
		for (int j = 1; j <= n; j++)
		{
			if (road2[i][j] > 0) cout << " --> " << j;
		}
		cout << endl;
	}
	system("pause");
}