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
int road_newmap[101][101];
map<int, string>dian_newmap;
extern void BuildMap()
{
	//Change_Window(60, 50);
	int n, m;
	cout << endl << "֪��У԰�������½���ͼ" << endl;
	cout << "================================================" << endl << endl;
	cout << "��ʼ������ͼ" << endl;
	cout << "��һ����¼�롰�㡱��Ϣ" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "���㡱�ĸ�����";
	cin >> n;
	cout << "------------------------------------------------" << endl;
	cout << "���������������ƣ��س�ȷ�������磺�ֿ����У�" << endl;
	string s;
	getline(cin, s);
	for (int i = 1; i <= n; i++)
	{
		cout << "��" << i << "��";
		getline(cin, s);
		dian_newmap[i] = s;
	}

	cout << "����Ϣ¼����ϡ���" << endl;
	Sleep(500);
	system("cls");
	cout << endl << "֪��У԰�������½���ͼ" << endl;
	cout << "================================================" << endl << endl;
	cout << "�ڶ�����¼�롰�ߡ���Ϣ" << endl;
	cout << "------------------------------------------------" << endl;
	cout << "���ߡ��ĸ�����";
	cin >> m;
	
	for (int i = 1; i <= m; i++)
	{
		system("cls");
		cout << endl << "֪��У԰�������½���ͼ" << endl;
		cout << "================================================" << endl << endl;
		cout << "����������ߵ���Ϣ���س�ȷ��" << endl;
		cout << "��ע�⣺����ʱ��������Ӧ�ı�ţ�" << endl;
		cout << endl;
		cout << "��ű�" << endl;
		for (auto i : dian_newmap)
		{
			cout << setw(3) << i.first << " " << i.second << endl;
		}
		cout << endl;
		cout << "��" << i << endl;
		cout << "��㣺";
		int x, y, l;
		cin >> x;
		cout << "�յ㣺";
		cin >> y;
		cout << "���ȣ�";
		cin >> l;
		road_newmap[x][y] = road_newmap[y][x] = l;
		
	}
	cout << "����Ϣ¼����ɡ���" << endl;
	Sleep(500);
	system("cls");
	cout << endl << "֪��У԰�������½���ͼ" << endl;
	cout << "================================================" << endl << endl;
	cout << "�������ļ���(������׺��������test)��";
	string filename;
	getline(cin, filename);
	getline(cin, filename);
	cout << "�����뵼���ĵ�ַ������000�򵼳���������ڸ�Ŀ¼" << endl;
	string newmap_address;
	getline(cin, newmap_address);
	if (newmap_address == "000")
		newmap_address = "./" + filename+".map";
	else
		newmap_address = newmap_address + "/" + filename + ".map";
	cout << "�����С���" << endl; 
	Sleep(500);
	system("cls");
	cout << "�ļ����յ�ַ��" << newmap_address << endl;
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
	cout << "������ɡ���" << endl;
	system("pause");
}